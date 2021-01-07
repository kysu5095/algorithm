// 탈옥

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <deque>
#include <string.h>
#include <limits.h>

using namespace std;

int test_case, h, w;
char arr[105][105];
bool visited[105][105][3];
int map[105][105];

class Point {
public:
	int y, x, c;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
Point pp[2];

void bfs(int _y, int _x, int n) {
	deque<Point> q;
	q.push_back({ _y, _x, 0 });
	visited[_y][_x][n] = true;
	int y, x, ny, nx, c;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		c = q.front().c;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny < 0 || ny == h + 2 || nx < 0 || nx == w + 2) continue;
			if (!visited[ny][nx][n] && arr[ny][nx] != '*') {
				visited[ny][nx][n] = true;
				if (arr[ny][nx] == '#') {
					map[ny][nx] += c + 1;
					q.push_back({ ny, nx, c + 1 });
				}
				else {
					map[ny][nx] += c;
					q.push_front({ ny, nx, c });
				}
			}
		}
	}
}

int meet_each() {
	int val = INT_MAX;
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			if (arr[i][j] == '*' || (!visited[i][j][0] && !visited[i][j][1] && !visited[i][j][2])) continue;
			if (arr[i][j] == '#')
				map[i][j] -= 2;
			if (val > map[i][j])
				val = map[i][j];
		}
	}
	return val;
}

int main() {
	int idx;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		idx = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
		scanf(" %d", &h);
		scanf(" %d", &w);
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (!i || i == h + 1 || !j || j == w + 1) {
					arr[i][j] = '.';
					continue;
				}
				scanf(" %1c", &arr[i][j]);
				if (arr[i][j] == '$') {
					pp[idx].y = i;
					pp[idx++].x = j;
				}
			}
		}
		bfs(0, 0, 0);
		bfs(pp[0].y, pp[0].x, 1);
		bfs(pp[1].y, pp[1].x, 2);
		printf("%d\n", meet_each());
	}
	return 0;
}