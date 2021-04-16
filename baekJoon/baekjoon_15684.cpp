// 사다리 조작

#include <stdio.h>

int w, m, h, goal;
bool find = false;
bool arr[31][11];

bool promising() {
	for (int j = 0; j < w; j++) {
		int x = j;
		int y = 0;
		while (y != h) {
			if (x - 1 >= 0 && arr[y][x - 1]) x--, y++;
			else if (arr[y][x]) x++, y++;
			else y++;
		}
		if (x != j) return false;
	}
	return true;
}

void dfs(int y, int x, int cnt) {
	if (find) return;
	if (cnt == goal) {
		if (promising()) find = true;
		return;
	}
	if (y == h) return;
	if (x == w - 1) {
		dfs(y + 1, 0, cnt);
		return;
	}
	if ((x && arr[y][x - 1]) || arr[y][x] || arr[y][x + 1]) {
		dfs(y, x + 1, cnt);
		return;
	}
	arr[y][x] = true;
	dfs(y, x + 1, cnt + 1);
	arr[y][x] = false;
	dfs(y, x + 1, cnt);
}

int put() {
	if (promising()) return 0;
	for (int i = 1; i <= 3; i++) {
		goal = i;
		dfs(0, 0, 0);
		if (find) return i;
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &w, &m, &h);
	while (m--) {
		int a, b;
		scanf(" %d %d", &a, &b);
		arr[a - 1][b - 1] = true;
	}
	printf("%d\n", put());
	return 0;
}