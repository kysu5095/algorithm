// 2048 (Easy)

#include <stdio.h>

int n, res = 0;
int arr[21][21][2], copy_arr[21][21], tmp[21][21], rotate[5];

void rotate_90() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j][0] = tmp[n - 1 - j][i], arr[i][j][1] = 0;
}

void rotate_180() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j][0] = tmp[n - 1 - i][n - 1 - j], arr[i][j][1] = 0;
}

void rotate_270() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j][0] = tmp[j][n - 1 - i], arr[i][j][1] = 0;
}

void move() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (!arr[i][j][0]) continue;
			int idx = j;
			int val = arr[i][idx][0];
			arr[i][idx][0] = 0;
			while (true) {
				idx--;
				if (arr[i][idx][0]) {
					if (arr[i][idx][0] == val) {
						if (arr[i][idx][1]) arr[i][idx + 1][0] = val;
						else {
							arr[i][idx][0] += val;
							arr[i][idx][1] = 1;
							res = res < arr[i][idx][0] ? arr[i][idx][0] : res;
						}
					}
					else arr[i][idx + 1][0] = val;
					break;
				}
				if (idx == 0) {
					arr[i][idx][0] = val;
					break;
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j][0] = copy_arr[i][j];
			arr[i][j][1] = 0;
		}
	}
}

void dfs(int idx) {
	if (idx == 5) {
		for (int i = 0; i < 5; i++) {
			if (rotate[i] == 1) rotate_90();
			else if (rotate[i] == 2) rotate_180();
			else if (rotate[i] == 3) rotate_270();
			move();
			if (rotate[i] == 1) rotate_270();
			else if (rotate[i] == 2) rotate_180();
			else if (rotate[i] == 3) rotate_90();
		}
		init();
		return;
	}
	for (int i = 0; i < 4; i++) {
		rotate[idx] = i;
		dfs(idx + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j][0]);
			copy_arr[i][j] = arr[i][j][0];
			res = res < arr[i][j][0] ? arr[i][j][0] : res;
		}
	}
	dfs(0);
	printf("%d\n", res);
	return 0;
}