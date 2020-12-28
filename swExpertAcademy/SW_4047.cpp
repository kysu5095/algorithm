// 영준이의 카드 카운팅

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, len, num;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		int S_size = 13, D_size = 13, H_size = 13, C_size = 13;
		bool is_error = false;
		char deck[1001];
		int S[14] = { 0, }, D[14] = { 0, }, H[14] = { 0, }, C[14] = { 0, };
		scanf(" %s", deck);

		len = strlen(deck);
		for (int i = 0; i < len - 2; i += 3) {
			if (is_error) break;
			num = ((deck[i + 1] - '0') * 10) + (deck[i + 2] - '0');
			switch (deck[i])
			{
			case 'S':
				if (S[num] == 0) S[num]++, S_size--;
				else is_error = true;
				break;
			case 'D':
				if (D[num] == 0) D[num]++, D_size--;
				else is_error = true;
				break;
			case 'H':
				if (H[num] == 0) H[num]++, H_size--;
				else is_error = true;
				break;
			case 'C':
				if (C[num] == 0) C[num]++, C_size--;
				else is_error = true;
				break;
			}
		}
		if (is_error) {
			printf("#%d ERROR\n", tc);
			continue;
		}
		printf("#%d %d %d %d %d\n", tc, S_size, D_size, H_size, C_size);
	}
	return 0;
}