// 로봇 청소기

#include <stdio.h>

int n, m;
int arr[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int move(int y, int x, int d) {
	arr[y][x] = 2;
	int ret = 1;
	int ny, nx, nd;
	while (true) {
		nd = d;
		for (int i = 0; i < 4; i++) {
			nd = (nd + 3) % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if (arr[ny][nx] == 0) {
				y = ny;
				x = nx;
				d = nd;
				arr[y][x] = 2;
				ret++;
				break;
			}
			if (i == 3) {
				nd = (d + 2) % 4;
				y += dy[nd];
				x += dx[nd];
				if (arr[y][x] == 1) return ret;
				break;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int y, x, d;
	scanf(" %d %d %d", &y, &x, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	printf("%d\n", move(y, x, d));
	return 0;
}