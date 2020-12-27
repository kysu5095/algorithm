// 불
// 6:45

#include <iostream>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

int test_case, w, h, res;
char arr[1001][1001];
bool visited[1001][1001];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<Point> fire;

void clearQ() {
	queue<Point> tmp;
	swap(fire, tmp);
}

int bfs(int _y, int _x) {
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = fire.size();
		while (len--) {
			y = fire.front().y;
			x = fire.front().x;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < w && nx >= 0 && nx < w && arr[ny][nx] == '.') {
					arr[ny][nx] = '*';
					fire.push({ ny, nx });
				}
			}
		}

		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny < 0 || ny == h || nx < 0 || nx == w)
					return t;
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && !visited[ny][nx] && arr[ny][nx] == '.') {
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sy, sx, val;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		clearQ();
		res = INT_MAX;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') sy = i, sx = j;
				else if (arr[i][j] == '*')
					fire.push({ i, j });
			}
		}
		arr[sy][sx] = '.';
		val = bfs(sy, sx);
		if (!val) cout << "IMPOSSIBLE\n";
		else cout << val << '\n';
	}
	return 0;
}