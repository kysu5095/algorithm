// 민석이의 과제 체크하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, n, k, tmp;
	int arr[101];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		for (int i = 0; i < 101; i++) 
			arr[i] = 1;
		scanf("%d", &n);
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &tmp);
			arr[tmp]--;
		}
		printf("#%d ", tc);
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}