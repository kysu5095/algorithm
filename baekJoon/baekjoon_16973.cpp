// 직사각형 탈출

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, h, w;
bool arr[1001][1001] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void is_construct() {
	int y, x;
	int len = v.size();
	for (int idx = 0; idx < len; idx++) {
		y = v[idx].first;
		x = v[idx].second;
		for (int i = y - (h - 1); i <= y; i++) {
			for (int j = x - (w - 1); j <= x; j++) {
				if (i < 0 || i == n || j < 0 || j == m) continue;
				arr[i][j] = true;
			}
		}
	}
    for (int i = n - (h - 1); i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < 0 || i == n || j < 0 || j == m || arr[i][j]) continue;
			arr[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - (w - 1); j < m; j++) {
			if (i < 0 || i == n || j < 0 || j == m || arr[i][j]) continue;
			arr[i][j] = true;
		}
	}
}

int bfs(const int sy, const int sx, const int& fy, const int& fx) {
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	arr[sy][sx] = true;
	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (y == fy && x == fx) return t;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx]) continue;
				arr[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, fy, fx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back(make_pair(i, j));
		}
	}
	cin >> h >> w >> sy >> sx >> fy >> fx;
	is_construct();
	cout << bfs(sy - 1, sx - 1, fy - 1, fx - 1) << '\n';
	return 0;
}