// 다솔이의 월급 상자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int test_case, n, x;
	float p;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		float sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%f %d", &p, &x);
			sum += (p * x);
		}
		printf("#%d %.6f\n", tc, sum);
	}
}