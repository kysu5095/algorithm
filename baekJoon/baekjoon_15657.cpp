// N과 M(8)

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int res[9];

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << res[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; i++) {
		res[cnt] = arr[i];
		dfs(i, cnt + 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}