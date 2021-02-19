// 우주 탐사선

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
int arr[11][11];
bool visited[11];
int ret = INT_MAX;

void dfs(int node, int cost) {
	if (ret <= cost) return;
	bool flag = true;
	for (int i = 0; i < n; i++)
		if (!visited[i]) flag = false;
	if (flag) {
		ret = cost;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, cost + arr[node][i]);
			visited[i] = false;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	visited[m] = true;
	dfs(m, 0);
	cout << ret << '\n';
	return 0;
}