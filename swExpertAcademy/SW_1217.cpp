// 거듭 제곱

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result;

void recur(int x, int y, int cnt, int val) {
	if (y == cnt) {
		result = val;
		return;
	}
	recur(x, y, cnt + 1, val * x);
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		int test_case, x, y;
		result = 0;
		scanf("%d", &test_case);
		scanf("%d %d", &x, &y);
		recur(x, y, 1, x);
		printf("#%d %d\n", tc, result);
	}
	return 0;
}