// 두 동전 언리미티드

#include <stdio.h>
#include <queue>

using namespace std;
int n, m;
char arr[21][21];
bool visited[21][21][21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int y1, x1, y2, x2;
};

int bfs(int y1, int x1, int y2, int x2) {
	queue<Point> q;
	q.push({ y1,x1,y2,x2 });
	visited[y1][x1][y2][x2] = true;

	int ny1, nx1, ny2, nx2, len, t = 0;
	bool flag1, flag2;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y1 = q.front().y1, x1 = q.front().x1;
			y2 = q.front().y2, x2 = q.front().x2;
			q.pop();

			for (int i = 0; i < 4; i++) {
				flag1 = false, flag2 = false;
				ny1 = y1 + dy[i], nx1 = x1 + dx[i];
				ny2 = y2 + dy[i], nx2 = x2 + dx[i];
				if (ny1 < 0 || ny1 == n || nx1 < 0 || nx1 == m) flag1 = true;
				if (ny2 < 0 || ny2 == n || nx2 < 0 || nx2 == m) flag2 = true;
				if (flag1 && flag2) continue;
				if (flag1 || flag2) return t;
				if (arr[ny1][nx1] == '#') ny1 = y1, nx1 = x1;
				if (arr[ny2][nx2] == '#') ny2 = y2, nx2 = x2;
				if (visited[ny1][nx1][ny2][nx2] || (ny1 == ny2 && nx1 == nx2)) continue;
				q.push({ ny1,nx1,ny2,nx2 });
				visited[ny1][nx1][ny2][nx2] = true;
			}
		}
	}
	return -1;
}

int main() {
	int idx = 0;
	int y1, x1, y2, x2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'o') {
				if (!idx) y1 = i, x1 = j, idx++;
				else y2 = i, x2 = j;
			}
		}
	}
	printf("%d\n", bfs(y1, x1, y2, x2));
	return 0;
}