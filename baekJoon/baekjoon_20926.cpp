// 얼음 미로

#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int w, h;
char map[501][501];
int arr[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs(int& sy, int& sx) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(sy, sx)));
	arr[sy][sx] = 0;
	int y, x, ny, nx, t, val;

	while (!pq.empty()) {
		t = -pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();
		if (arr[y][x] < t) continue;

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			val = t;
			while (true) {
				if (ny < 0 || ny == h || nx < 0 || nx == w) break;
				if (map[ny][nx] == 'R' || map[ny][nx] == 'H' || map[ny][nx] == 'E') break;
				val += (map[ny][nx] - '0');
				ny += dy[i];
				nx += dx[i];
			}
			if (ny < 0 || ny == h || nx < 0 || nx == w || map[ny][nx] == 'H') continue;
			if (map[ny][nx] == 'E') {
				if (val < arr[ny][nx])
					arr[ny][nx] = val;
				continue;
			}
			ny -= dy[i];
			nx -= dx[i];
			if (ny == y && nx == x) continue;
			if (val >= arr[ny][nx]) continue;
			pq.push(make_pair(-val, make_pair(ny, nx)));
			arr[ny][nx] = val;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, fy, fx;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		cin >> map[i];
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'T') {
				sy = i;
				sx = j;
				map[i][j] = '0';
			}
			else if (map[i][j] == 'E') {
				fy = i;
				fx = j;
			}
			arr[i][j] = INT_MAX;
		}
	}
	bfs(sy, sx);
	if (arr[fy][fx] == INT_MAX) cout << "-1\n";
	else cout << arr[fy][fx] << '\n';
	return 0;
}