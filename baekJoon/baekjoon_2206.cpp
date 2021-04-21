// 벽 부수고 이동하기

#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
char arr[1001][1001];
bool visited[1001][1001][2];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct Point {
	int y, x, boom;
};

int bfs() {
	queue<Point> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = true;
	int y, x, ny, nx, boom, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			boom = q.front().boom;
			if (y == n - 1 & x == m - 1) return t;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (arr[ny][nx] == '0') {
					if (visited[ny][nx][boom]) continue;
					q.push({ ny, nx, boom });
					visited[ny][nx][boom] = true;
				}
				else {
					if (boom || visited[ny][nx][boom + 1]) continue;
					q.push({ ny, nx, boom + 1 });
					visited[ny][nx][boom + 1] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", arr[i]);
	printf("%d\n", bfs());
	return 0;
}