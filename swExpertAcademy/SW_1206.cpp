// View

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	int n, sum, tmp1, tmp2, minV, idx;
	bool jud;
	int arr[1001];
	for (int tc = 1; tc <= 10; tc++) {
		sum = 0;
		tmp1 = 0;
		tmp2 = 0;
		idx = 0;
		jud = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = 2; i < n - 2; i++) {
			jud = false;
			minV = 256;
			for (int j = 1; j <= 2; j++) {
				tmp1 = arr[i] - arr[i - j];
				tmp2 = arr[i] - arr[i + j];
				if (tmp1 <= 0 || tmp2 <= 0) {
					jud = true;
					break;
				}
				if (minV > tmp1) {
					minV = tmp1;
					idx = i - j;
				}
				if (minV > tmp2) {
					minV = tmp2;
					idx = i + j;
				}
			}
			if (jud == false)
				sum += (arr[i] - arr[idx]);
		}
		printf("#%d %d\n", tc, sum);
	}
	return 0;
}