// 블록 게임

#include <iostream>
#include <queue>

using namespace std;

int n, m, res = 0;
double k;
char arr[202][202];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int ddy[4] = { -1, -1, 1, 1 };
int ddx[4] = { -1, 1, 1, -1 };
int dddy[4][3] = { {0, -1, -1}, {0, -1, -1}, {0, 1, 1}, {0, 1, 1} };
int dddx[4][3] = { {-1, 0, -1}, {1, 0, 1}, {1, 0, 1}, {-1, 0, -1} };

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	arr[y][x] = 'O';
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny > n || nx < 0 || nx > m) continue;
			if (arr[ny][nx] == '.') q.push(make_pair(ny, nx));
			if (arr[ny][nx] == 'B') {
				q.push(make_pair(ny, nx));
				arr[ny][nx] = 'O';
			}
		}
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	n *= 2;
	m *= 2;
	k *= 2;
	for (int i = 0; i < n + 1; i++)
		cin >> arr[i];
	int y = n, x = k, d = 0;
	int ny, nx;
	while (true) {
		for (int i = 0; i < 3; i++) {
			ny = y + dddy[d][i], nx = x + dddx[d][i];
			if (arr[ny][nx] == 'B') 
				res += bfs(ny, nx);
		}
		y += ddy[d], x += ddx[d];
		if (y == n) break;
		if (y == 0 && x == 0) d = 2;
		else if (y == 0 && x == m) d == 3;
		else if (y == 0) {
			if (d == 0) d = 3;
			else if (d == 1) d = 2;
		}
		else if (x == 0) {
			if (d == 0) d = 1;
			else if (d == 3) d = 2;
		}
		else if (x == m) {
			if (d == 1) d = 0;
			else if (d == 2) d = 3;
		}
	}
	cout << res << '\n';
	return 0;
}