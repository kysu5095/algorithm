// 최대 상금

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_case, n, len, res;

void dfs(int idx, int cnt, char arr[]) {
	if (cnt == n) {
		int tmp = atoi(arr);
		res = res < tmp ? tmp : res;
		return;
	}
	for (int i = idx; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[j] >= arr[i]) {
				char tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				dfs(i, cnt + 1, arr);
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		char arr[7];
		scanf(" %s %d", arr, &n);
		res = atoi(arr);
		len = strlen(arr);
		dfs(0, 0, arr);
		printf("#%d %d\n", tc, res);
	}
	return 0;
}