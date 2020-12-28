// 스타트 택시

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m, f, ty, tx;
int arr[21][21];
bool visited[21][21] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
pair<int, int> taxi[404];

class Point {
public:
	int y, x;
	bool operator < (const Point& p) const {
		if (y > p.y) return false;
		else if (y < p.y) return true;
		else {
			if (x > p.x) return false;
			else return true;
		}
	}
};

void bfs() {
	queue<pair<int, int>> q;
	vector<Point> v;
	int y, x, ny, nx, sy, sx, fy, fx, len, cnt;
	bool flag;
	while (true) {
		q.push(make_pair(ty, tx));
		visited[ty][tx] = true;
		// 출발지 찾기
		while (!q.empty()) {
			len = q.size();
			while (len--) {
				y = q.front().first;
				x = q.front().second;
				q.pop();
				if (arr[y][x] > 1 && arr[y][x] < 500)
					v.push_back({ y, x });
				for (int i = 0; i < 4; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
					if (arr[ny][nx] == 1 || visited[ny][nx]) continue;
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
			// 찾음
			if (v.size()) break;
			f--;
			if (f == 0) {
				f = -1;
				return;
			}
		}
		// 출발지까지 갈 수 없음
		if (v.empty()) {
			f = -1;
			return;
		}
		sort(v.begin(), v.end());
		sy = v[0].y;
		sx = v[0].x;
		fy = taxi[arr[sy][sx]].first;
		fx = taxi[arr[sy][sx]].second;
		arr[sy][sx] = 0;

		// 초기화
		while (!q.empty()) q.pop();
		memset(visited, false, sizeof(visited));
		q.push(make_pair(sy, sx));
		visited[sy][sx] = true;
		cnt = 1;
		flag = false;

		// 도착지 찾기
		while (!q.empty()) {
			len = q.size();
			while (len-- && !flag) {
				y = q.front().first;
				x = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
					if (arr[ny][nx] == 1 || visited[ny][nx]) continue;
					// 도착지 찾음
					if (ny == fy && nx == fx) {
						f--;
						f += (cnt << 1);
						ty = ny;
						tx = nx;
						//arr[ny][nx] = 0;
						m--;
						flag = true;
						break;
					}
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
			if (flag) break;
			cnt++;
			f--;
			if (f == 0) {
				f = -1;
				return;
			}
		}
		// 도착지 못찾음
		if (!flag) {
			f = -1;
			return;
		}
		// 모든 승객 이동 완료
		if (m == 0) break;
		while (!q.empty()) q.pop();
		v.clear();
		memset(visited, false, sizeof(visited));
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, fy, fx;
	cin >> n >> m >> f;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cin >> ty >> tx;
	ty--;
	tx--;
	int idx = 2;
	for (int i = 0; i < m; i++) {
		cin >> sy >> sx >> fy >> fx;
		arr[sy - 1][sx - 1] = idx;
		taxi[idx].first = fy - 1;
		taxi[idx].second = fx - 1;
		idx++;
	}
	bfs();
	cout << f << '\n';
	return 0;
}

