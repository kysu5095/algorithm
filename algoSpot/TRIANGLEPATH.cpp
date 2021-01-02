// 삼각형 위의 최대 경로

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int test_case, n;
int arr[101][101];
int dp[101][101];

int triangle(int y, int x) {
	if (y == n - 1) return arr[y][x];
	int& ret = dp[y][x];
	if (ret) return ret;

	return ret = max(triangle(y + 1, x), triangle(y + 1, x + 1)) + arr[y][x];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> arr[i][j];
		memset(dp, 0, sizeof(dp));
		cout << triangle(0, 0) << '\n';
	}
	return 0;
}