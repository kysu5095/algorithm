// 동철이의 프로그래밍 대회

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	//freopen("sample_input (14).txt", "r", stdin);
	int test_case, n, m;
	int input, cnt;
	int arr[21];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &m);
		int max_num = 0,max_cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt = 0;
			for (int j = 0; j < m; j++) {
				scanf("%d", &input);
				if (input == 1)
					cnt++;
			}
			arr[i] = cnt;
			if (max_cnt < cnt)
				max_cnt = cnt;
		}
		for (int i = 0; i < n; i++) {
			if (arr[i] == max_cnt)
				max_num++;
		}
		printf("#%d %d %d\n", tc, max_num, max_cnt);
	}
	return 0;
}