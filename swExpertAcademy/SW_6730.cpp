// 장애물 경주 난이도

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

int main() {
	//freopen("input.txt", "r", stdin);
	int test_case, sz;
	int arr[101];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &sz);
		for (int i = 0; i < sz; i++)
			scanf("%d", &arr[i]);
		int maxV = -1001;
		int minV = 1001;
		int tmp;
		for (int i = 0; i < sz - 1; i++) {
			tmp = -(arr[i] - arr[i + 1]);
			maxV = std::max(maxV, tmp);
			minV = std::min(minV, tmp);
		}
		if (maxV < 0) maxV = 0;
		if (minV > 0) minV = 0;
		printf("#%d %d %d\n", tc, maxV, -minV);
	}
	return 0;
}