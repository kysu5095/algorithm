// 달이 차오른다, 가자.
//3:50

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[51][51];
bool visited[64][51][51] = { { {false, } ,}, };

class Point {
public:
	int y, x, c, k;
	Point(int _y, int _x, int _c, int _k) {
		y = _y;
		x = _x;
		c = _c;
		k = _k;
	}
};
Point p[4] = { {0, 1, 0, 0}, {0, -1, 0, 0}, {1, 0, 0, 0}, {-1, 0, 0, 0} };

int bfs(int sy, int sx) {
	queue<Point> q;
	q.push({ sy, sx, 0, 0 });
	visited[0][sy][sx] = true;
	int y, x, ny, nx, c, k, nk, len;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		c = q.front().c;
		k = q.front().k;
		q.pop();
		if (arr[y][x] == '1')
			return c;

		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[k][ny][nx] && arr[ny][nx] != '#') {
				if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') {
					nk = k | (1 << (arr[ny][nx] - 'a'));
					visited[nk][ny][nx] = true;
					q.push({ ny, nx, c + 1, nk });
				}
				else if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F') {
					if (k & (1 << (arr[ny][nx] - 'A'))) {
						visited[k][ny][nx] = true;
						q.push({ ny, nx, c + 1, k });
					}
				}
				else {
					visited[k][ny][nx] = true;
					q.push({ ny, nx, c + 1, k });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sy, sx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0')
				sy = i, sx = j;
		}
	}
	cout << bfs(sy, sx) << '\n';
	return 0;
}