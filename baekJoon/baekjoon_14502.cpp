// 연구소

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m, cnt = 0, res = 0;
int arr[9][9];
bool visited[9][9];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (auto& it : v) {
		q.push(make_pair(it.first, it.second));
		visited[it.first][it.second] = true;
	}
	int y, x, ny, nx, emt = cnt;
	while (!q.empty() && emt) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx] == 1) continue;
			if (arr[ny][nx] == 0) emt--;
			if (emt <= res) return;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	res = res < emt ? emt : res;
}

void dfs(int y, int x, int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	if (y == n) return;
	if (x == m) {
		dfs(y + 1, 0, cnt);
		return;
	}
	if (arr[y][x] == 1 || arr[y][x] == 2) {
		dfs(y, x + 1, cnt);
		return;
	}
	arr[y][x] = 1;
	dfs(y, x + 1, cnt + 1);
	arr[y][x] = 0;
	dfs(y, x + 1, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 2) v.push_back(make_pair(i, j));
			else if (arr[i][j] == 0) cnt++;
		}
	}
	cnt -= 3;
	dfs(0, 0, 0);
	printf("%d\n", res);
	return 0;
}