// 경사로

#include <stdio.h>

int n, L;
int arr[101][201];

int main() {
	scanf("%d %d", &n, &L);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
			arr[j][i + n] = arr[i][j];
	int ret = 0;
	for (int j = 0; j < n + n; j++) {
		int i, x = 1;
		for (i = 0; i < n - 1; i++) {
			if (arr[i][j] == arr[i + 1][j]) x++;
			else if (arr[i][j] + 1 == arr[i + 1][j] && x >= L) x = 1;
			else if (arr[i][j] - 1 == arr[i + 1][j] && x >= 0) x = 1 - L;
			else break;
		}
		if (i == n - 1 && x >= 0) ret++;
	}
	printf("%d\n", ret);
	return 0;
}