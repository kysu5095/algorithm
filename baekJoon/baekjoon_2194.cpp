// 유닛 이동시키기
// 9:20

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, A, B, k;
bool arr[501][501] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void is_construct() {
	int y, x, len = v.size();
	for (int idx = 0; idx < len; idx++) {
		y = v[idx].first;
		x = v[idx].second;
		for (int i = y - (A - 1); i <= y; i++) {
			for (int j = x - (B - 1); j <= x; j++) {
				if (i < 0 || i == n || j < 0 || j == m || arr[i][j]) continue;
				arr[i][j] = true;
			}
		}
	}
	for (int i = n - (A - 1); i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < 0 || i == n || j < 0 || j == m || arr[i][j]) continue;
			arr[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - (B - 1); j < m; j++) {
			if (i < 0 || i == n || j < 0 || j == m || arr[i][j]) continue;
			arr[i][j] = true;
		}
	}
}

int bfs(int sy, int sx, int fy, int fx) {
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
	cin >> n >> m >> A >> B >> k;
	for (int i = 0; i < k; i++) {
		cin >> sy >> sx;
		v.push_back(make_pair(sy - 1, sx - 1));
	}
	cin >> sy >> sx >> fy >> fx;
	is_construct();
	cout << bfs(sy - 1, sx - 1, fy - 1, fx - 1) << '\n';
	return 0;
}