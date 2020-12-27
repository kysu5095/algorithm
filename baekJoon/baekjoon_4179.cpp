// 불!

#include <iostream>
#include <queue>

using namespace std;

int r, c;
char arr[1001][1001];
bool visited[1001][1001] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0 ,0 };
queue<pair<int, int>> fire;

int bfs(int sy, int sx) {
	queue<pair<int, int>> jh;
	jh.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx, len, cnt = 1;
	while (!jh.empty() || !fire.empty()) {
		len = fire.size();
		while (len--) {
			y = fire.front().first;
			x = fire.front().second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c) continue;
				if (arr[ny][nx] == '#' || arr[ny][nx] == 'F') continue;
				arr[ny][nx] = 'F';
				fire.push(make_pair(ny, nx));
			}
		}
		len = jh.size();
		while (len--) {
			y = jh.front().first;
			x = jh.front().second;
			jh.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c) return cnt;
				if (visited[ny][nx] || arr[ny][nx] == '#' || arr[ny][nx] == 'F') continue;
				visited[ny][nx] = true;
				jh.push(make_pair(ny, nx));
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, fy, fx;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'J') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == 'F')
				fire.push(make_pair(i, j));
		}
	}
	int res = bfs(sy, sx);
	if (res == -1) cout << "IMPOSSIBLE\n";
	else cout << res << '\n';
	return 0;
}