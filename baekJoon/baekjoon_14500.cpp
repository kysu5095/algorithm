// 테트로미노

#include <stdio.h>

int n, m, res = 0;
int arr[501][501];
bool visited[501][501];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x, int cnt, int total) {
	if (cnt == 3) {
		res = res < total ? total : res;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		dfs(ny, nx, cnt + 1, total + arr[ny][nx]);
		visited[ny][nx] = false;
	}
}

void another(int y, int x, int total) {
	for (int i = 0; i < 4; i++) {
		int tmp = total;
		for (int j = i; j < i + 3; j++) {
			int ny = y + dy[(j % 4)];
			int nx = x + dx[(j % 4)];
			if (ny < 0 || ny == n || nx < 0 || nx == m) break;
			tmp += arr[ny][nx];
			res = res < tmp ? tmp : res;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, arr[i][j]);
			another(i, j, arr[i][j]);
			visited[i][j] = false;
		}
	}
	printf("%d\n", res);
	return 0;
}