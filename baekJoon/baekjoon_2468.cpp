// 안전 영역
// 2:20

#include <iostream>
#include <queue>

using namespace std;

int n, res = 0;
int arr[101][101];
bool visited[101][101][101] = { { {false, }, }, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs(int _y, int _x, int k) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));
	visited[k][_y][_x] = true;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[k][ny][nx] && arr[ny][nx] > k) {
				visited[k][ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max_v = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			max_v = max_v < arr[i][j] ? arr[i][j] : max_v;
		}
	}
	int tmp;
	for (int h = 0; h <= max_v; h++) {
		tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[h][i][j] && arr[i][j] > h) {
					bfs(i, j, h);
					tmp++;
				}
			}
		}
		res = res < tmp ? tmp : res;
	}
	cout << res << '\n';
	return 0;
}