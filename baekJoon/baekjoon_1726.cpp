// 로봇
// 1:05

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, m, res = INT_MAX;
int arr[101][101];
bool visited[101][101][4] = { { {false, }, }, };

class Point {
public:
	int y, x, d;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs(int _sd, int _sy, int _sx, int _dd, int _dy, int _dx) {
	queue<Point> q;
	q.push({ _sy, _sx, _sd });
	visited[_sy][_sx][_sd] = true;
	int y, x, d, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			d = q.front().d;
			if (y == _dy && x == _dx && d == _dd) {
				res = t;
				return;
			}
			q.pop();

			if (d == 0 || d == 1) {
				if (!visited[y][x][2]) {
					visited[y][x][2] = true;
					q.push({ y, x, 2 });
				}
				if (!visited[y][x][3]) {
					visited[y][x][3] = true;
					q.push({ y, x, 3 });
				}
			}
			else {
				if (!visited[y][x][0]) {
					visited[y][x][0] = true;
					q.push({ y, x, 0 });
				}
				if (!visited[y][x][1]) {
					visited[y][x][1] = true;
					q.push({ y, x, 1 });
				}
			}
			for (int i = 1; i <= 3; i++) {
				y += p[d].y;
				x += p[d].x;
				if (y >= 0 && y < m && x >= 0 && x < n && !arr[y][x]) {
					if (visited[y][x][d]) continue;
					visited[y][x][d] = true;
					q.push({ y, x, d });
				}
				else
					break;
			}
		}
		t++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sd, sy, sx, dd, dy, dx;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cin >> sy >> sx >> sd;
	cin >> dy >> dx >> dd;
	bfs(sd - 1, sy - 1, sx - 1, dd - 1, dy - 1, dx - 1);
	cout << res << '\n';
	return 0;
}

