// 명탐정 준하

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int complete;
char arr[4][6];
bool visited[4][5][(1 << 20) + 1];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int y, x, path;
	char next;
};

int char_to_int(char& ch) {
	if (ch >= '0' && ch <= '9') return (ch - '0');
	else return (ch - 'A' + 10);
}

int bfs(int sy, int sx) {
	queue<Point> q;
	q.push({ sy, sx, 1 << (sy * 5 + sx), '0' });
	visited[sy][sx][1 << (sy * 5 + sx)] = true;

	int y, x, ny, nx, path, npath, len, t = 0;
	char next;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			path = q.front().path;
			next = q.front().next;
			q.pop();
			if (path == complete) return t;

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == 4 || nx < 0 || nx == 5 || arr[ny][nx] == '.') continue;
				if (arr[ny][nx] != '#' && char_to_int(arr[ny][nx]) > char_to_int(next) + 1) continue;
				npath = path | (1 << (ny * 5 + nx));
				if (visited[ny][nx][npath]) continue;
				if (arr[ny][nx] == '#') q.push({ ny, nx, npath, next });
				else q.push({ ny, nx, npath, max(next, arr[ny][nx]) });
				visited[ny][nx][npath] = true;
			}
		}
		t++;
	}
	return -1;
}

int main() {
	int tc, sy, sx;
	scanf("%d", &tc);
	while (tc--) {
		complete = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%s", arr[i]);
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == '0') sy = i, sx = j;
				if (arr[i][j] != '.') complete |= (1 << (i * 5 + j));
			}
		}
		printf("%d\n", bfs(sy, sx));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}