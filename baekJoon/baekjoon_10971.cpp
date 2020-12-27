// 외판원 순회

#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;

int n, cost = INT_MAX;
int arr[16][16];
bool visited[16] = { false, };

void dfs(int idx, int start, int sum, int cnt) {
	if (idx == start && cnt == n) {
		cost = cost > sum ? sum : cost;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!arr[idx][i]) continue;
		if (!visited[i] && sum + arr[idx][i] < cost) {
			visited[i] = true;
			dfs(i, start, sum + arr[idx][i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dfs(0, 0, 0, 0);
	cout << cost << '\n';
	return 0;
}