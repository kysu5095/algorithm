// GNS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char num[11][4] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	freopen("input.txt", "r", stdin);
	int test_case, len;
	int arr[10];
	char str[3];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		scanf("%s", str);
		scanf("%d", &len);
		for (int i = 0; i < len; i++) {
			scanf("%s", str);
			if (strcmp(str, "ZRO") == 0)
				arr[0]++;
			else if (strcmp(str, "ONE") == 0)
				arr[1]++;
			else if (strcmp(str, "TWO") == 0)
				arr[2]++;
			else if (strcmp(str, "THR") == 0)
				arr[3]++;
			else if (strcmp(str, "FOR") == 0)
				arr[4]++;
			else if (strcmp(str, "FIV") == 0)
				arr[5]++;
			else if (strcmp(str, "SIX") == 0)
				arr[6]++;
			else if (strcmp(str, "SVN") == 0)
				arr[7]++;
			else if (strcmp(str, "EGT") == 0)
				arr[8]++;
			else if (strcmp(str, "NIN") == 0)
				arr[9]++;
		}
		printf("#%d\n", tc);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%s ", num[i]);
			}
		}
		printf("\n");
	}

	return 0;
}