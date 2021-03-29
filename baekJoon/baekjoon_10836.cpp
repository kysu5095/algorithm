// 여왕벌

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[701][701];
int n, t;

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < t; i++) {
		int y = n - 1;
		int x = 0;
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		while (a--) {
			if (y) y--;
			else x++;
		}
		while (b--) {
			arr[y][x]++;
			if (y) y--;
			else x++;
		}
		while (c--) {
			arr[y][x] += 2;
			if (y) y--;
			else x++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!i || !j) printf("%d ", arr[i][j] + 1);
			else printf("%d ", arr[0][j] + 1);
		}
		printf("\n");
	}
	return 0;
}