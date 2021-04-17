// 연구소 3

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, m, virus = 0, ret = INT_MAX;
int arr[51][51];
bool visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

int bfs() {
	int y, x, ny, nx, len, t = 0, cnt = virus;
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		y = v[i].first;
		x = v[i].second;
		if (arr[y][x] == 3) {
			q.push(make_pair(y, x));
			visited[y][x] = true;
		}
	}
	while (!q.empty()) {
		if (cnt == 0) return t;
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] == 1) continue;
				if (arr[ny][nx] == 0) cnt--;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
	return INT_MAX;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int val = bfs();
		ret = ret > val ? val : ret;
		return;
	}
	if (idx == v.size()) return;
	arr[v[idx].first][v[idx].second] = 3;
	dfs(idx + 1, cnt + 1);
	arr[v[idx].first][v[idx].second] = 2;
	dfs(idx + 1, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 2) v.push_back(make_pair(i, j));
			else if (arr[i][j] == 0) virus++;
		}
	}
	dfs(0, 0);
	if (ret == INT_MAX) ret = -1;
	printf("%d\n", ret);
	return 0;
}