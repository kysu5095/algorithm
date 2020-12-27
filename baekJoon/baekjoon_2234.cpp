// 성곽
// 6:40

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m, cnt = 1;
int arr[51][51];
bool visited[51][51];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int bfs(int _y, int _x) {
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int y, x, ny, nx, c = 1;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		// 서 : 1   북 : 2   동 : 4   남 : 8
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < m && nx >= 0 && nx < n && !visited[ny][nx]) {
				if (!(arr[y][x] & (1 << i))) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
					c++;
				}
			}
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max1 = 0, max2 = 0;
	int res1 = 0, res2 = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				max1 = bfs(i, j);
				res1 = res1 < max1 ? max1 : res1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (arr[i][j] & (1 << k)) {
					memset(visited, false, sizeof(visited));
					arr[i][j] -= (1 << k);
					max2 = bfs(i, j);
					res2 = res2 < max2 ? max2 : res2;
					arr[i][j] += (1 << k);
				}
			}
		}
	}

	cnt--;
	cout << cnt << '\n';
	cout << res1 << '\n';
	cout << res2 << '\n';
	return 0;
}