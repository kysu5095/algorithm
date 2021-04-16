// 퇴사

#include <stdio.h>

int n, res = 0;
int arr[16][2];

void dfs(int idx, int total) {
	res = res < total ? total : res;
	for (int i = idx; i <= n; i++) {
		if (arr[i][0] + i > n + 1) continue;
		dfs(arr[i][0] + i, total + arr[i][1]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d %d", &arr[i][0], &arr[i][1]);
	dfs(1, 0);
	printf("%d\n", res);
	return 0;
}