// 변신 이동 게임

#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, t, r, c;
char arr[501][501];
int visited[501][501][2] = { { {0,},}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs() {
	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	pq.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	visited[0][0][0] = 0;
	int y, x, ny, nx, tt, s;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		tt = -pq.top().first.first;
		s = pq.top().first.second;
		pq.pop();
		// 변신X
		if (tt <= visited[y][x][0]) {
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
				if (tt + 1 < visited[ny][nx][0]) {
					visited[ny][nx][0] = tt + 1;
					pq.push(make_pair(make_pair(-(tt + 1), 0), make_pair(ny, nx)));
				}
			}
		}
		// 변신
		if (s == 0) {
			tt += t;
			s = 1;
		}

		if (tt <= visited[y][x][1]) {
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				while (true) {
					if (ny < 0 || ny == n || nx < 0 || nx == n) break;
					if (arr[ny][nx] == '#') {
						if (tt + 1 < visited[ny][nx][1]) {
							visited[ny][nx][1] = tt + 1;
							pq.push(make_pair(make_pair(-(tt + 1), 1), make_pair(ny, nx)));
						}
						break;
					}
					ny += dy[i];
					nx += dx[i];
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t >> r >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	r--;
	c--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j][0] = visited[i][j][1] = INT_MAX;

	bfs();
	cout << min(visited[r][c][0], visited[r][c][1]) << '\n';
	return 0;
}