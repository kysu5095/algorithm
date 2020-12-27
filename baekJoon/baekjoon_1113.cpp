// 수영장 만들기
// 12:30

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51][10] = { { {false,},}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int _y, int _x, int d) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));
	visited[_y][_x][d] = true;
	int y, x, ny, nx, t = 1;
	bool flag = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) {
				flag = false;
				continue;
			}
			if (visited[ny][nx][d]) continue;
			if (arr[ny][nx] >= d) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx][d] = true;
			t++;
		}
	}
	if (flag) return t;
	else return 0;
}

int main() {
	int max = 0, res = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &arr[i][j]);
			max = max < arr[i][j] ? arr[i][j] : max;
		}
	}
	for (int d = max; d >= 1; d--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] < d && !visited[i][j][d])
					res += bfs(i, j, d);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}