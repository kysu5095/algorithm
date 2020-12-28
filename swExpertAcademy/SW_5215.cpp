// 행버거 다이어트

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test_case, n, t, res;

class Flavor {
public:
	int point, calory;
};
Flavor flavor[21];

void dfs(int idx, int point, int sum) {
	res = res < point ? point : res;
	for (int i = idx; i < n; i++) {
		if (sum + flavor[i].calory <= t)
			dfs(i + 1, point + flavor[i].point, sum + flavor[i].calory);
	}
}

int main() {
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		scanf(" %d %d", &n, &t);
		for (int i = 0; i < n; i++)
			scanf(" %d %d", &flavor[i].point, &flavor[i].calory);
		dfs(0, 0, 0);
		printf("#%d %d\n", tc, res);
	}
	return 0;
}