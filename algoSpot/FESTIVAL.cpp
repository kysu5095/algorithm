// 록 페스티벌

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

int test_case, n, l, s;
double ret;
int arr[1001], sum_arr[1001];

int main() {
	scanf("%d", &test_case);
	while (test_case--) {
		s = 0;
		ret = LLONG_MAX;
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &l);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			s += arr[i];
			sum_arr[i] = s;
		}
		for (int i = l; i <= n; i++)
			for (int j = 0; j <= i - l; j++)
				ret = std::min(ret, (double)(sum_arr[i] - sum_arr[j]) / (i - j));
		printf("%.10lf\n", ret);
	}
	return 0;
}