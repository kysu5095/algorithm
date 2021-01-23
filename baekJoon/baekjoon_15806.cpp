// 영우의 기숙사 청소

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m, k, t;
int arr[301][301];
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
queue<pair<int, int>> q, inspect;

bool spread() {
	int y, x, ny, nx, len, val;
	for (int T = 1; T <= t; T++) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (arr[ny][nx] == 2) continue;
				val = T % 2;
				if (arr[ny][nx] == -1) {
					q.push(make_pair(ny, nx));
					arr[ny][nx] = val;
				}
				else {
					if (arr[ny][nx] == val) continue;
					arr[ny][nx] = 2;
				}
			}
		}
	}
	val = t % 2;
	while (!inspect.empty()) {
		y = inspect.front().first;
		x = inspect.front().second;
		inspect.pop();
		if (arr[y][x] == -1) continue;
		if (arr[y][x] == 2 || arr[y][x] == val) return true;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x;
	memset(arr, -1, sizeof(arr));
	cin >> n >> m >> k >> t;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		q.push(make_pair(y - 1, x - 1));
		arr[y - 1][x - 1] = 0;
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		inspect.push(make_pair(y - 1, x - 1));
	}
	if (spread()) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}