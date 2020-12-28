// Magnetic

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, result;
	int arr[100][100];
	//freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		result = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (arr[i][j] == 1) {
					while (++i < n) {
						if (arr[i][j] == 2) {
							result++;
							break;
						}
					}
				}
			}
		}

		printf("#%d %d\n", tc, result);
	}

	return 0;
}