// 삼성시의 버스 노선

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int test_case, n, A, B, p, C;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		int station[5005] = { 0, };
		int station_cnt[505] = { 0, };
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			scanf(" %d %d", &A, &B);
			for (int j = A; j <= B; j++)
				station[j]++;
		}
		scanf(" %d", &p);
		for (int i = 0; i < p; i++) 
			scanf(" %d", &station_cnt[i]);
		printf("#%d ", tc);
		for (int i = 0; i < p; i++)
			printf("%d ", station[station_cnt[i]]);
		printf("\n");
	}
	return 0;
}