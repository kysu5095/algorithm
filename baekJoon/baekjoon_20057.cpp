// 마법사 상어와 토네이도

#include <stdio.h>

int n, res = 0;
int arr[500][500];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int ddy[4][9] =		{ {-2, -1, -1, -1, 0, 1, 1, 1, 2},
					  {-1, -1, 0, 0, 0, 0, 1, 1, 2},
					  {-2, -1, -1, -1, 0, 1, 1, 1, 2},
					  {-2, -1, -1, 0, 0, 0, 0, 1, 1} };
int ddx[4][9] =		{ {0, -1, 0, 1, -2, -1, 0, 1, 0},
					  {-1, 1, -2, -1, 1, 2, -1, 1, 0},
					  {0, -1, 0, 1, 2, -1, 0, 1, 0},
					  {0, -1, 1, -2, -1, 1, 2, -1, 1} };
int percent[4][9] = { { 2, 10, 7, 1, 5, 10, 7, 1, 2 },
					  { 1, 1, 2, 7, 7, 2, 10, 10, 5},
					  {2, 1, 7, 10, 5, 1, 7, 10, 2},
					  {5, 10, 10, 2, 7, 7, 2, 1, 1} };

void wind(int& y, int& x, int& d) {
	int total = arr[y][x];
	int ny, nx, rate;
	for (int i = 0; i < 9; i++) {
		ny = y + ddy[d][i];
		nx = x + ddx[d][i];
		rate = total * percent[d][i] / 100;
		arr[y][x] -= rate;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) res += rate;
		else arr[ny][nx] += rate;
	}
	ny = y + dy[d];
	nx = x + dx[d];
	if (ny < 0 || ny >= n || nx < 0 || nx >= n) res += arr[y][x];
	else arr[ny][nx] += arr[y][x];
	arr[y][x] = 0;
}

void tonado() {
	int y = n / 2, x = n / 2;
	int d = 0, move = 1;
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < move; j++) {
				y += dy[d];
				x += dx[d];
				if (x == -1) return;
				wind(y, x, d);
			}
			d = (d + 1) % 4;
		}
		move++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	tonado();
	printf("%d\n", res);
	return 0;
}