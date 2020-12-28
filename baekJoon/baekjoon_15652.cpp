// N과 M(4)

#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[cnt] = i;
		dfs(i, cnt + 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(1, 0);
	return 0;
}