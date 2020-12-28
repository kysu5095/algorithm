// 상남자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, L, R;
int arr[1001][1001];
bool visited[1001][1001] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int return_cnt(int _y, int& x, int l, int r, queue<pair<pair<int, int>, pair<int, int>>>& q) {
	q.push(make_pair(make_pair(_y, x), make_pair(l, r)));
	int cnt = 1;
	int y = _y + dy[2];
	while (true) {
		if (y == n) break;
		if (arr[y][x] == 1) break;
		visited[y][x] = true;
		q.push(make_pair(make_pair(y, x), make_pair(l, r)));
		y += dy[2];
		cnt++;
	}
	y = _y + dy[3];
	while (true) {
		if (y == -1) break;
		if (arr[y][x] == 1) break;
		visited[y][x] = true;
		q.push(make_pair(make_pair(y, x), make_pair(l, r)));
		y += dy[3];
		cnt++;
	}

	return cnt;
}

int bfs(int _y, int _x) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	visited[_y][_x] = true;
	int cnt = return_cnt(_y, _x, L, R, q);
	int y, x, ny, nx, l, r;
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		l = q.front().second.first;
		r = q.front().second.second;
		q.pop();
		if (l != 0) {
			nx = x + dx[1];
			if (!(arr[y][nx] == 1 || visited[y][nx] || nx < 0 || nx == m)) {
				visited[y][nx] = true;
				cnt += return_cnt(y, nx, l - 1, r, q);
			}
		}
		if (r != 0) {
			nx = x + dx[0];
			if (!(arr[y][nx] == 1 || visited[y][nx] || nx < 0 || nx == m)) {
				visited[y][nx] = true;
				cnt += return_cnt(y, nx, l, r - 1, q);
			}
		}
	}
	return cnt;
}

int main() {
	int sy, sx;
	scanf("%d %d %d %d", &n, &m, &L, &R);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &arr[i][j]);
			if (arr[i][j] == 2) {
				sy = i;
				sx = j;
			}
		}
	printf("%d\n", bfs(sy, sx));
	return 0;
}