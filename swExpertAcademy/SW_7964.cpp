// 7964 부먹왕국의 차원 관문

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, city, d, res;
	int* arr;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d %d", &city, &d);
		res = 0;
		arr = new int[city + 5];
		memset(arr, 0, sizeof(arr));
		arr[0] = 1;
		for (int i = 1; i <= city; i++)
			scanf(" %d", &arr[i]);

		int cnt = 1;
		for (int i = 1; i <= city; i++) {
			if (arr[i] == 0) {
				if (cnt == d) {
					res++;
					cnt = 1;
				}
				else
					cnt++;
			}
			else
				cnt = 1;
		}
		printf("#%d %d\n", tc, res);
		delete[] arr;
	}
	return 0;
}