// 다리 만들기
// 12:30

#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>

using namespace std;

int n, res = INT_MAX;
int arr[101][101];
bool visited[101][101] = { {false,}, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs(int &_y, int &_x, int val) {
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		arr[y][x] = val;
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int get_length(int &_y, int &_x, int &val) {
	memset(visited, false, sizeof(visited));
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int tmp = 0;
	int y, x, ny, nx, len;
	while (!q.empty()) {
		len = q.size();
		if (tmp >= res) return INT_MAX;
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
					if (!visited[ny][nx] && arr[ny][nx] != val) {
						if (arr[ny][nx]) return tmp;
						q.push({ ny, nx });
						visited[ny][nx] = true;
					}
				}
			}
		}
		tmp++;
	}
	return INT_MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int val = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j])
				bfs(i, j, val++);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				val = get_length(i, j, arr[i][j]);
				res = res > val ? val : res;
			}
		}
	}
	cout << res << '\n';
	return 0;
}