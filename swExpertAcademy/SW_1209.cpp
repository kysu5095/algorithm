// Sum

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int arr[101][101];
	int input;
	//freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &input);
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				scanf("%d", &arr[i][j]);

		int maxV = 0, sum = 0;

		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[i][j];
			}
			maxV = maxV < sum ? sum : maxV;
		}

		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[j][i];
			}
			maxV = maxV < sum ? sum : maxV;
		}

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[i][i];
		maxV = maxV < sum ? sum : maxV;

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[99 - i][i];
		maxV = maxV < sum ? sum : maxV;

		printf("#%d %d\n", tc, maxV);
	}
	return 0;
}