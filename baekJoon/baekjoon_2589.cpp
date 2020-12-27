// 보물섬

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m, res = 0;
char arr[51][51];
int visited[51][51];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs(int _y, int _x) {
	memset(visited, 0, sizeof(visited));
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = 1;
	int y, x, ny, nx, val;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		val = visited[y][x];
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && arr[ny][nx] == 'L') {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
	return val - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				tmp = bfs(i, j);
				res = res < tmp ? tmp : res;
			}
		}
	}
	cout << res << '\n';
	return 0;
}