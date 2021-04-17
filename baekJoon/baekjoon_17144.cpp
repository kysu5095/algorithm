// 미세먼지 안녕!

#include <stdio.h>
#include <string.h>
#include <utility>

int r, c, t;
int arr[51][51], tmp[51][51];
std::pair<int, int> p[2];
int dy[2][4] = { {0, -1, 0, 1}, {0, 1, 0, -1} };
int dx[2][4] = { {1, 0, -1, 0}, {1, 0, -1, 0} };

void spread() {
	memset(tmp, 0, sizeof(tmp));
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (arr[y][x] == 0 || arr[y][x] == -1) continue;
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[0][i];
				int nx = x + dx[0][i];
				if (ny < 0 || ny == r || nx < 0 || nx == c || arr[ny][nx] == -1) continue;
				tmp[ny][nx] += (arr[y][x] / 5);
				cnt++;
			}
			arr[y][x] -= (arr[y][x] / 5 * cnt);
		}
	}
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			arr[y][x] += tmp[y][x];
}

void aircondition() {
	for (int idx = 0; idx < 2; idx++) {
		int y = p[idx].first;
		int x = p[idx].second + 1;
		int d = 0;
		int prev = 0, next;
		while (true) {
			next = arr[y][x];
			arr[y][x] = prev;
			y += dy[idx][d];
			x += dx[idx][d];
			if (y < 0 || y == r || x < 0 || x == c || arr[y][x] == -1) {
				if (arr[y][x] == -1) break;
				y -= dy[idx][d];
				x -= dx[idx][d];
				d++;
				y += dy[idx][d];
				x += dx[idx][d];
			}
			prev = next;
		}
	}
}

int main() {
	int idx = 0;
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == -1)
				p[idx++] = std::make_pair(i, j);
		}
	}
	while (t--) {
		spread();
		aircondition();
	}
	int ret = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			ret += arr[i][j];
	printf("%d\n", ret + 2);
	return 0;
}