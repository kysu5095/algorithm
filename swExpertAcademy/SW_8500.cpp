// 극장 좌석

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int test_case, n, input, sum;
	int arr[10001];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		std::sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			if (i == 0)
				sum += (arr[i] * 2 + 1);
			else
				sum += (arr[i] * 2 + 1 - arr[i - 1]);
		}
		printf("#%d %d\n", tc, sum);
	}
}