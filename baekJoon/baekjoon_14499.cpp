// 주사위 굴리기

#include <stdio.h>

int n, m, y, x, k;
int arr[21][21];
int dp[6];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void move(int d) {
	y += dy[d];
	x += dx[d];
	if (y < 0 || y == n || x < 0 || x == m) {
		y -= dy[d];
		x -= dx[d];
		return;
	}
	int val = dp[0];
	if (d == 0) {
		dp[0] = dp[3];
		dp[3] = dp[5];
		dp[5] = dp[2];
		dp[2] = val;
	}
	else if (d == 1) {
		dp[0] = dp[2];
		dp[2] = dp[5];
		dp[5] = dp[3];
		dp[3] = val;
	}
	else if (d == 2) {
		dp[0] = dp[4];
		dp[4] = dp[5];
		dp[5] = dp[1];
		dp[1] = val;
	}
	else {
		dp[0] = dp[1];
		dp[1] = dp[5];
		dp[5] = dp[4];
		dp[4] = val;
	}
	if (!arr[y][x]) arr[y][x] = dp[5];
	else {
		dp[5] = arr[y][x];
		arr[y][x] = 0;
	}
	printf("%d\n", dp[0]);
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	while (k--) {
		int d;
		scanf(" %d", &d);
		move(d - 1);
	}
	return 0;
}