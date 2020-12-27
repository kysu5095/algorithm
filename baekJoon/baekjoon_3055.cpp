// 탈출
// 2:30

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int r, c, res;
int desy, desx;
char arr[51][51];
bool visited[51][51] = { {false, }, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<Point> water;

void bfs(int dy, int dx) {
	queue<Point> dochi;
	dochi.push({ dy, dx });
	visited[dy][dx] = true;

	int y, x, ny, nx, len, cnt = 0;
	while (!dochi.empty()) {
		cnt++;
		len = water.size();
		while (len--) {
			y = water.front().y;
			x = water.front().x;
			water.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < r && nx >= 0 && nx < c && arr[ny][nx] == '.') {
					water.push({ ny, nx });
					arr[ny][nx] = '*';
				}
			}
		}

		len = dochi.size();
		while (len--) {
			y = dochi.front().y;
			x = dochi.front().x;
			dochi.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[ny][nx] && arr[ny][nx] != '*' && arr[ny][nx] != 'X') {
					if (ny == desy && nx == desx) {
						res = cnt;
						return;
					}
					dochi.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dy, dx;
	res = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') dy = i, dx = j;
			else if (arr[i][j] == '*') water.push({ i, j });
			else if (arr[i][j] == 'D') desy = i, desx = j;
		}
	}
	arr[dy][dx] = '.';
	bfs(dy, dx);
	if (!res) cout << "KAKTUS\n";
	else cout << res << '\n';
	return 0;
}