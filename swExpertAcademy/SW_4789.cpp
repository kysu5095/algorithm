// 성공적인 공연 기획

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, len, cnt, res;
	char arr[1005];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(arr, 0, sizeof(arr));
		scanf(" %s", arr);
		len = (int)strlen(arr);
		cnt = arr[0] - '0';
		for (int i = 1; i < len; i++) {
			if (arr[i] - '0' == 0) continue;
			if (i > cnt) {
				res += (i - cnt);
				cnt += (i - cnt + (arr[i] - '0'));
			}
			else
				cnt += (arr[i] - '0');
		}
		printf("#%d %d\n", tc, res);
	}
	return 0;
}