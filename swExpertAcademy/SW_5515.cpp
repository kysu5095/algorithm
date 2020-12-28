// 2016년 요일 맞추기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int month[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	int test_case, m, d, total;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf("%d", &m);
		scanf("%d", &d);
		total = month[m - 1] + d;
		printf("#%d %d\n", tc, (total + 3) % 7);
	}
	return 0;
}