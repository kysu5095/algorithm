// 상원이의 연속 합

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, res;

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 1;
		scanf("%d", &n);

		int cnt = 2;
		while (true) {
			if ((cnt * (cnt + 1)) / 2 > n)
				break;
			int num = 1;
			int sum = 0;
			for (int i = 0; i < cnt; i++)
				sum += (num + i);
			while (true) {
				if (sum > n) break;
				if (sum == n) {
					res++;
					break;
				}
				sum += cnt;
			}
			cnt++;
		}
		printf("#%d %d\n", tc, res);
	}
	return 0;
}