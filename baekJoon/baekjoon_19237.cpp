// 어른 상어

#include <stdio.h>
#include <string.h>

int n, m, k, cnt;
int arr[21][21], tmp[21][21], smell[21][21][2];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ds[401][4][4];
struct SHARK {
	bool die;
	int y, x, d;
}s[401];

void put_smell() {
	for (int idx = 1; idx <= m; idx++) {
		if (s[idx].die) continue;
		smell[s[idx].y][s[idx].x][0] = idx;
		smell[s[idx].y][s[idx].x][1] = k;
	}
}
		
void delete_smell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smell[i][j][1]) {
				smell[i][j][1]--;
				if (smell[i][j][1] == 0)
					smell[i][j][0] = 0;
			}
		}
	}
}

void move() {
	memset(tmp, 0, sizeof(tmp));
	for (int idx = 1; idx <= m; idx++) {
		if (s[idx].die) continue;
		int y = s[idx].y;
		int x = s[idx].x;
		int d = s[idx].d;
		bool find = false;
		arr[y][x] = 0;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[ds[idx][d][i]];
			int nx = x + dx[ds[idx][d][i]];
			if (ny < 0 || ny == n || nx < 0 || nx == n || smell[ny][nx][0]) continue;
			if (tmp[ny][nx]) {
				s[idx].die = true;
				cnt--;
				find = true;
				break;
			}
			s[idx].y = ny;
			s[idx].x = nx;
			s[idx].d = ds[idx][d][i];
			tmp[ny][nx] = idx;
			find = true;
			break;
		}
		if (find) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[ds[idx][d][i]];
			int nx = x + dx[ds[idx][d][i]];
			if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
			if (smell[ny][nx][0] == idx) {
				s[idx].y = ny;
				s[idx].x = nx;
				s[idx].d = ds[idx][d][i];
				break;
			}
		}
	}
}

void redraw() {
	for (int idx = 1; idx <= m; idx++) {
		if (s[idx].die) continue;
		arr[s[idx].y][s[idx].x] = idx;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j])
				s[arr[i][j]] = { false, i, j, 0 };
		}
	}
	for (int i = 1; i <= m; i++) {
		int d;
		scanf(" %d", &d);
		s[i].d = d - 1;
	}
	for (int idx = 1; idx <= m; idx++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int d;
				scanf(" %d", &d);
				ds[idx][i][j] = d - 1;
			}
		}
	}
	cnt = m;
	int t = 0;
	while (t <= 1000 && cnt != 1) {
		t++;
		put_smell();
		move();
		redraw();
		delete_smell();
	}
	if (t == 1001) t = -1;
	printf("%d\n", t);
	return 0;
}