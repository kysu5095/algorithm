// 연구소

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, _cnt = 0, ret = 0;
int arr[9][9];
bool visited[9][9];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v,virus;

int bfs() {
	int y, x, ny, nx, cnt = _cnt;
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (auto& it : virus) {
		q.push(it);
		visited[it.first][it.second] = true;
	}
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx] == 1) continue;
			if (arr[ny][nx] == 0) cnt--;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int val = bfs();
		ret = ret < val ? val : ret;
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		arr[v[i].first][v[i].second] = 1;
		dfs(i + 1, cnt + 1);
		arr[v[i].first][v[i].second] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 0) _cnt++, v.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	_cnt -= 3;
	dfs(0, 0);
	printf("%d\n", ret);
	return 0;
}