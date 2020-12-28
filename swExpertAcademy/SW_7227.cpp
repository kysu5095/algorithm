// 사랑의 카운슬러

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int test_case, n;
long long res;
bool snail[21];

class Point {
public:
	int y, x;
};
Point *p;

void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		long long x = 0, y = 0, sum;
		for (int i = 0; i < n; i++) {
			if (snail[i]) {
				x += p[i].x;
				y += p[i].y;
			}
			else {
				x -= p[i].x;
				y -= p[i].y;
			}
		}
		sum = x * x + y * y;
		if (res == -1 || res > sum)
			res = sum;
		return;
	}
	for (int i = idx; i < n; i++) {
		if (!snail[i]) {
			snail[i] = true;
			dfs(i + 1, cnt + 1);
			snail[i] = false;
		}
	}
}

int main() {
	int y, x;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d", &n);
		res = -1;
		memset(snail, false, sizeof(snail));
		p = new Point[n];
		for (int i = 0; i < n; i++) {
			scanf(" %d %d", &x, &y);
			p[i].y = y, p[i].x = x;
		}
		dfs(0, 0);
		printf("#%d %lld\n", tc, res);
		delete[] p;
	}
	return 0;
}