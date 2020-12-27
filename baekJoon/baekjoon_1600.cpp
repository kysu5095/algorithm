// 말이 되고픈 원숭이
// 3:55 - 4:10  > 5:20

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int k, w, h;
int arr[201][201];
bool visited[201][201][32] = { { {false, }, }, };

class Point {
public:
	int y, x, c, d;
};
Point p[12] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
				{1, -2}, {2, -1}, {2, 1}, {1, 2},
				{0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs() {
	int res = INT_MAX;
	queue<Point> q;
	q.push({ 0, 0, k, 0 });
	visited[0][0][k] = true;
	int y, x, ny, nx, c, d;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		c = q.front().c;
		d = q.front().d;
		q.pop();
		if (y == h - 1 && x == w - 1) {
			res = res > d ? d : res;
			continue;
		}
		for (int i = 0; i < 12; i++) {
			if (!c && (i >= 0 && i < 8)) continue;
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < h && nx >= 0 && nx < w && !arr[ny][nx]) {
				if (i >= 0 && i < 8) {
					if (!visited[ny][nx][c - 1]) {
						visited[ny][nx][c - 1] = true;
						q.push({ ny, nx, c - 1, d + 1 });
					}
				}
				else {
					if (!visited[ny][nx][c]) {
						visited[ny][nx][c] = true;
						q.push({ ny, nx, c, d + 1 });
					}
				}
			}
		}
	}
	if (res == INT_MAX) res = -1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr[i][j];
	cout << bfs() << '\n';
	return 0;
}