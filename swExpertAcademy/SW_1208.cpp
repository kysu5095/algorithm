// Flatten

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int main() {
	int cycle;
	int arr[101];
	//freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &cycle);
		for (int i = 0; i < 100; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < cycle; i++) {
			std::sort(arr, arr + 100);	
			if (arr[99] - arr[0] <= 1) break;
			arr[99]--;
			arr[0]++;
		}
		std::sort(arr, arr + 100);
		printf("#%d %d\n", tc, arr[99] - arr[0]);
	}
}