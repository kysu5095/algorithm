// 회문1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, result = 0;
char arr[8][8];
char tmp[8];

void horizontal(int y, int x) {
	if (x + n > 8) return;

	for (int i = 0; i < n; i++)
		tmp[i] = arr[y][x + i];
	int half = n / 2 - 1;
	while (half >= 0) {
		if (tmp[half] != tmp[n - half - 1])
			return;
		half--;
	}
	/*printf("horizontal=========\n");
	printf("%s\n", tmp);*/
	result++;
}

void vertical(int y, int x) {
	if (y + n > 8) return;

	for (int i = 0; i < n; i++)
		tmp[i] = arr[y + i][x];
	int half = n / 2 - 1;
	while (half >= 0) {
		if (tmp[half] != tmp[n - half - 1])
			return;
		half--;
	}
	/*printf("vertical=========\n");
	printf("%s\n", tmp);*/
	result++;
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		result = 0;
		scanf("%d", &n);
		for (int i = 0; i < 8; i++)
			scanf("%s", arr[i]);

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				horizontal(i, j);
				vertical(i, j);
			}
		}
		printf("#%d %d\n", tc, result);
	}
	
	return 0;
}