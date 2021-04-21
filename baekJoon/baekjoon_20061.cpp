// 모노미노도미노 2

#include <stdio.h>

int n, total = 0;
int arr[2][6][4];

void down_1by1(int x, int idx) {
	for (int y = 1; y < 5; y++) {
		if (arr[idx][y + 1][x]) {
			arr[idx][y][x] = 1;
			return;
		}
	}
	arr[idx][5][x] = 1;
}

void down_1by2(int x, int idx) {
	for (int y = 1; y < 5; y++) {
		if (arr[idx][y + 1][x] || arr[idx][y + 1][x + 1]) {
			arr[idx][y][x] = 1;
			arr[idx][y][x + 1] = 1;
			return;
		}
	}
	arr[idx][5][x] = 1;
	arr[idx][5][x + 1] = 1;
}

void down_2by1(int x, int idx) {
	for (int y = 1; y < 5; y++) {
		if (arr[idx][y + 1][x]) {
			arr[idx][y][x] = 1;
			arr[idx][y - 1][x] = 1;
			return;
		}
	}
	arr[idx][5][x] = 1;
	arr[idx][4][x] = 1;
}

void down_arr(int _y, int idx) {
	for (int y = _y - 1; y >= 0; y--)
		for (int x = 0; x < 4; x++)
			arr[idx][y + 1][x] = arr[idx][y][x];
	for (int x = 0; x < 4; x++)
		arr[idx][0][x] = 0;
}

void is_full(int idx) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int y = 5; y >= 2; y--) {
			int cnt = 0;
			for (int x = 0; x < 4; x++) {
				if (arr[idx][y][x]) cnt++;
				else break;
			}
			if (cnt == 4) {
				down_arr(y, idx);
				total++;
				flag = true;
				break;
			}
		}
	}
}

void is_over(int idx) {
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < 4; x++)
			if (arr[idx][1][x])
				down_arr(5, idx);
	}
}

void get_score(int& score, int idx) {
	for (int y = 2; y < 6; y++)
		for (int x = 0; x < 4; x++)
			if (arr[idx][y][x]) score++;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		int t, x, y;
		scanf(" %d %d %d", &t, &y, &x);
		if (t == 1) {
			down_1by1(x, 0);
			down_1by1(y, 1);
		}
		else if (t == 2) {
			down_1by2(x, 0);
			down_2by1(y, 1);
		}
		else {
			down_2by1(x, 0);
			down_1by2(y, 1);
		}
		is_full(0);
		is_full(1);
		is_over(0);
		is_over(1);
	}
	int green = 0, blue = 0;
	get_score(green, 0);
	get_score(blue, 1);
	printf("%d\n%d\n", total, blue + green);
	return 0;
}