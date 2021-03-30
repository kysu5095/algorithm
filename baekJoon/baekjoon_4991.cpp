// 로봇 청소기

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <map>

using namespace std;

int w, h, cnt, res;
char arr[21][21];
bool visited[21][21][(1 << 10) + 2];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
map<pair<int, int>, int> m;

int bfs(int y, int x) {
	int complete = 0;
	for (int i = 0; i < cnt; i++) complete += (1 << i);
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(y, x)));
	memset(visited, false, sizeof(visited));
	visited[y][x][0] = true;

	int ny, nx, cur, ncur, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			cur = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == h || nx < 0 || nx == w || visited[ny][nx][cur] || arr[ny][nx] != '.') continue;
				ncur = cur;
				if (m.count(make_pair(ny, nx))) {
					ncur |= (1 << m[make_pair(ny, nx)]);
					if (ncur == complete) return t;
				}
				q.push(make_pair(ncur, make_pair(ny, nx)));
				visited[ny][nx][ncur] = true;
			}
		}
	}
	return -1;
}

int main() {
	while (true) {
		scanf(" %d %d", &w, &h);
		if (!w && !h) break;
		m.clear();
		res = INT_MAX;
		cnt = 0;
		int y, x;
		for (int i = 0; i < h; i++) {
			scanf("%s", arr[i]);
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 'o') {
					arr[i][j] = '.';
					y = i;
					x = j;
				}
				else if (arr[i][j] == '*') {
					arr[i][j] = '.';
					m[make_pair(i, j)] = cnt++;
				}
			}
		}
		printf("%d\n", bfs(y, x));
	}
	return 0;
}