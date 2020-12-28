// 직사각형 길이 찾기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, n, input;
	int arr[101];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < 3; i++) {
			scanf("%d", &input);
			arr[input]++;
		}
		printf("#%d ", tc);
		for (int i = 0; i < 101; i++) {
			if (arr[i] != 0 && (arr[i] % 2) == 1) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}