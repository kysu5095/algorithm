// 거스름돈

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int *arr = new int[n + 1];
	fill(arr, arr + n + 1, INT_MAX - 1);
	arr[0] = 0;
	for (int i = 2; i <= n; i++)
		arr[i] = min(arr[i - 2] + 1, arr[i]);
	for (int i = 5; i <= n; i++)
		arr[i] = min(arr[i - 5] + 1, arr[i]);
	if (arr[n] == INT_MAX - 1) cout << "-1\n";
	else cout << arr[n] << '\n';
	return 0;
}