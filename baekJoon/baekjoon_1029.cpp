// 그림 교환

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int arr[16][16];
int dp[16][1 << 15 + 1][10];

int draw(int cur, int visited, int price) {
	if (visited == (1 << n) - 1) return 1;
	int& ref = dp[cur][visited][price];
	if (ref) return ref;
	ref = 1;
	for (int i = 1; i < n; i++) {
		if (!(visited & (1 << i)) && arr[cur][i] >= price)
			ref = max(ref, draw(i, visited | (1 << i), arr[cur][i]) + 1);
	}
	return ref;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %1d", &arr[i][j]);
	memset(dp, 0, sizeof(dp));
	printf("%d\n", draw(0, 1, 0));
	return 0;
}