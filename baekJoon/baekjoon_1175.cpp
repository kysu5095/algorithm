// 배달

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[51][51];
bool visited[3][4][51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

class Point {
public:
	bool first, second;
	int y, x, d;
};

int bfs(int& sy, int& sx) {
	queue<Point> q;
	for (int i = 0; i < 4; i++) {
		q.push({ false, false, sy, sx, i });
		visited[0][i][sy][sx] = true;
	}
	bool first, second;
	int y, x, ny, nx, d, num, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			first = q.front().first, second = q.front().second;
			y = q.front().y; x = q.front().x, d = q.front().d;
			q.pop();
			if (!first && !second) num = 0;
			else if (first) num = 1;
			else num = 2;
			for (int i = 0; i < 4; i++) {
				if (i == d) continue;
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx] == '#' || visited[num][i][ny][nx]) continue;
				if (arr[ny][nx] == '1') {
					if (second) return t;
					q.push({ true, false, ny, nx, i });
					visited[1][i][ny][nx] = true;
				}
				else if (arr[ny][nx] == '2') {
					if (first) return t;
					q.push({ false, true, ny, nx, i });
					visited[2][i][ny][nx] = true;
				}
				else {
					q.push({ first, second, ny, nx, i });
					visited[num][i][ny][nx] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx = 1, sy, sx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'C') {
				arr[i][j] = idx + '0';
				idx++;
			}
			else if (arr[i][j] == 'S') {
				sy = i;
				sx = j;
			}
		}
	}
	cout << bfs(sy, sx) << '\n';
	return 0;
}