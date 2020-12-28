// 부분 수열의 합

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int test_case, n, k, res;
int arr[21];

void dfs(int idx, int sum) {
	if (sum >= k) {
		if (sum == k) res++;
		return;
	}
	for (int i = idx; i < n; i++) {
		dfs(i + 1, sum + arr[i]);
	}
}

int main() {
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(arr, 0, sizeof(arr));
		scanf(" %d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf(" %d", &arr[i]);
		dfs(0, 0);
		printf("#%d %d\n", tc, res);
	}
	return 0;
}