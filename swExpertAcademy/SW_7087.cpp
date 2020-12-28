// 문제 제목 붙이기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, n, cnt;
	bool title[30];
	char tmpTitle[31];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		cnt = 0;
		memset(title, false, sizeof(title));
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			scanf(" %s", tmpTitle);
			if (title[int(tmpTitle[0]) - 65] == false)
				title[int(tmpTitle[0]) - 65] = true;
		}
		for (int i = 0; i < 30; i++) {
			if (!title[i])
				break;
			cnt++;
		}
		printf("#%d %d\n", tc, cnt);
	}

	return 0;
}