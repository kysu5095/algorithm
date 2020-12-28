// 상호의 배틀필드

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char map[21][21], command[101];
int test_case, h, w, n;

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void game(int _y, int _x, int _d) {
	int y = _y, x = _x, d = _d;
	for (int i = 0; i < n; i++) {
		switch (command[i]){
		case 'U':
			d = 3;
			if (y - 1 >= 0 && map[y - 1][x] == '.') {
				map[y][x] = '.';
				y -= 1;
			}
			break;
		case 'D':
			d = 2;
			if (y + 1 < h && map[y + 1][x] == '.') {
				map[y][x] = '.';
				y += 1;
			}
			break;
		case 'L':
			d = 1;
			if (x - 1 >= 0 && map[y][x - 1] == '.') {
				map[y][x] = '.';
				x -= 1;
			}
			break;
		case 'R':
			d = 0;
			if (x + 1 < w && map[y][x + 1] == '.') {
				map[y][x] = '.';
				x += 1;
			}
			break;
		case 'S':
			int ny = y, nx = x;
			while (true) {
				ny += p[d].y, nx += p[d].x;
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) break;
				if (map[ny][nx] == '#') break;
				if (map[ny][nx] == '*') {
					map[ny][nx] = '.';
					break;
				}
			}
			break;
		}
	}
	if (d == 0) map[y][x] = '>';
	else if (d == 1) map[y][x] = '<';
	else if (d == 2) map[y][x] = 'v';
	else if (d == 3) map[y][x] = '^';
}

int main() {
	freopen("input.txt", "r", stdin);
	int y, x, d;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d %d", &h, &w);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '<' || map[i][j] == '>' || map[i][j] == 'v' || map[i][j] == '^') {
					y = i, x = j;
					if (map[i][j] == '<') d = 1;
					else if (map[i][j] == '>') d = 0;
					else if (map[i][j] == 'v') d = 2;
					else if (map[i][j] == '^') d = 3;
				}
			}
		}
		scanf(" %d", &n);
		scanf(" %s", command);
		game(y, x, d);
		printf("#%d ", tc);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}