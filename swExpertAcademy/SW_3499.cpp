// 퍼팩트 셔플

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int test_case, n, deck1, deck2;
	char str[1001][85];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d", &n);
		for (int i = 0; i < n; i++)
			scanf(" %s", str[i]);
		deck1 = 0;
		if (n % 2 == 0)
			deck2 = n / 2;
		else
			deck2 = n / 2 + 1;

		printf("#%d ", tc);
		for (int i = 0; i < n / 2; i++)
			printf("%s %s ", str[deck1++], str[deck2++]);
		if (n % 2 != 0)
			printf("%s", str[deck1]);
		printf("\n");
	}
	return 0;
}