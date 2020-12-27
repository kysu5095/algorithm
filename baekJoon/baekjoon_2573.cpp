// 빙산
// 12:00

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, m ,cnt = 0;
int arr[301][301];
bool visited[301][301];

class Point {
public:
	int y, x, val;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> v;

bool is_separate() {
	memset(visited, false, sizeof(visited));
	queue<Point> q;
	q.push({ v[0].y, v[0].x });
	visited[v[0].y][v[0].x] = true;
	int len = v.size();
	int tmp = 0;
	int y, x, ny, nx;
	while (!q.empty()) {
		tmp++;
		y = q.front().y;
		x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && arr[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
	if (tmp != len) return true;
	else return false;
}

bool melt() {
	int y, x, ny, nx, val, tmp;
	while (true) {
		cnt++;
		int len = v.size();
		for (int i = 0; i < len; i++) {
			y = v[i].y;
			x = v[i].x;
			val = v[i].val;
			tmp = 0;
			for (int j = 0; j < 4; j++) {
				ny = y + p[j].y;
				nx = x + p[j].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && !arr[ny][nx])
					tmp++;
			}
			v[i].val = val - tmp;
		}
		for (int i = 0; i < len; i++) {
			if (v[i].val <= 0) {
				arr[v[i].y][v[i].x] = 0;
				v.erase(v.begin() + i);
				i--;
				len--;
			}
			else
				arr[v[i].y][v[i].x] = v[i].val;
		}
		if (v.empty()) return false;
		if (is_separate()) return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back({ i, j, arr[i][j] });
		}
	}
	if (melt()) cout << cnt << '\n';
	else cout << "0\n";
	return 0;
}