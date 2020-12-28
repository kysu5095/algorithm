// 모음이 보이지 않는 사람

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	int test_case;
	char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
	char word[51];
	int jud[51];

	freopen("input.txt", "r", stdin);

	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(word, 0, sizeof(word));
		memset(jud, 0, sizeof(jud));
		scanf("%s", &word);
		for (int i = 0; i < strlen(word); i++) {
			for (int j = 0; j < 5; j++) {
				if (word[i] == vowel[j]) {
					jud[i] = 1;
					break;
				}
			}
		}

		printf("#%d ", tc);
		for (int i = 0; i < strlen(word); i++) {
			if (jud[i] == 0)
				printf("%c", word[i]);
		}
		printf("\n");
	}
	return 0;
}