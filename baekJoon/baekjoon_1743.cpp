// 음식물 피하기

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, res = -1;
bool arr[101][101] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs(int _y, int _x) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));
	arr[_y][_x] = false;
	int y, x, ny, nx, cnt = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || !arr[ny][nx]) continue;
			cnt++;
			arr[ny][nx] = false;
			q.push(make_pair(ny, nx));
		}
	}
	res = max(res, cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x;
	cin >> n >> m >> k;
	while (k--) {
		cin >> y >> x;
		arr[y - 1][x - 1] = true;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j])
				bfs(i, j);
	cout << res << '\n';
	return 0;
}