// N-Queen

#include <iostream>
#include <math.h>

using namespace std;

int n, cnt = 0;
int arr[16];

bool promising(int& depth) {
	for (int i = 0; i < depth; i++) 
		if (arr[i] == arr[depth] || abs(depth - i) == abs(arr[depth] - arr[i])) return false;
	return true;
}

void dfs(int depth) {
	if (promising(depth)) {
		if (depth == n - 1) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			arr[depth + 1] = i;
			dfs(depth + 1);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[0] = i;
		dfs(0);
	}
	cout << cnt << '\n';
	return 0;
}