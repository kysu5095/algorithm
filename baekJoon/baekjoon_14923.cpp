// 미로 탈출
// 4:05

#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool arr[1001][1001];
bool visited[1001][1001][2] = { { {false, } ,}, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int sy, int sx, int ly, int lx) {
	queue<pair<bool, pair<int, int>>> q;
	q.push(make_pair(true, make_pair(sy, sx)));
	visited[sy][sx][true] = true;
	int y, x, ny, nx, len, t = 0;
	bool flag;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			flag = q.front().first;
			q.pop();
			if (y == ly && x == lx) return t;

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (arr[ny][nx]) {
					if (flag) {
						if (!visited[ny][nx][false]) {
							visited[ny][nx][false] = true;
							q.push(make_pair(false, make_pair(ny, nx)));
						}
					}
				}
				else {
					if (!visited[ny][nx][flag]) {
						visited[ny][nx][flag] = true;
						q.push(make_pair(flag, make_pair(ny, nx)));
					}
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, dy, dx;
	cin >> n >> m >> sy >> sx >> dy >> dx;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	cout << bfs(sy - 1, sx - 1, dy - 1, dx - 1) << '\n';
	return 0;
}