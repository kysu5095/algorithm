// 통나무 옮기기
// 7:35

#include <iostream>
#include <queue>

using namespace std;

int n, res;
char arr[51][51];
bool visited[51][51][2] = { { {false, } , }, };

class Point {
public:
	int y, x, d;
};
Point p[8] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1} };
Point tree[3];

// d = 0 (가로)    
// d = 1 (세로)
int bfs(int direction) {
	queue<Point> q;
	q.push({ tree[1].y, tree[1].x, direction });
	visited[tree[1].y][tree[1].x][direction] = true;
	int y, x, ny, nx, d, len, t = 0;
	int y1, x1, y2, x2, ny1, nx1, ny2, nx2;
	bool flag;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			d = q.front().d;
			q.pop();
			if (d) {
				y1 = y - 1, x1 = x;
				y2 = y + 1, x2 = x;
			}
			else {
				y1 = y, x1 = x - 1;
				y2 = y, x2 = x + 1;
			}
			if (arr[y][x] == 'E' && arr[y1][x1] == 'E' && arr[y2][x2] == 'E')
				return t;
			
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				ny1 = y1 + p[i].y;
				nx1 = x1 + p[i].x;
				ny2 = y2 + p[i].y;
				nx2 = x2 + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < n && ny1 >= 0 && ny1 < n && nx1 >= 0 && nx1 < n && ny2 >= 0 && ny2 < n && nx2 >= 0 && nx2 < n) {
					if (!visited[ny][nx][d] && arr[ny][nx] != '1' && arr[ny1][nx1] != '1' && arr[ny2][nx2] != '1') {
						visited[ny][nx][d] = true;
						q.push({ ny, nx, d });
					}
				}
			}
			flag = true;
			for (int i = 0; i < 8; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (!(ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != '1')) {
					flag = false;
					break;
				}
			}
			if (flag && !visited[y][x][!d]) {
				visited[y][x][!d] = true;
				q.push({ y, x, !d });
			}
		}
		t++;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d, idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
				tree[idx++] = { i, j };
		}
	}
	if (tree[0].y + 1 == tree[1].y) d = 1;
	else d = 0;
	res = bfs(d);
	cout << res << '\n';
	return 0;
}