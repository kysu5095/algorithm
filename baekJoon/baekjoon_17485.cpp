// 진우의 달 여행 (Large)

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001][3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	for (int x = 0; x < m; x++)
		for (int i = 0; i < 3; i++)
			dp[0][x][i] = arr[0][x];
	for (int y = 1; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (x == 0) {
				dp[y][x][0] = INT_MAX;
				dp[y][x][1] = dp[y - 1][x][2] + arr[y][x];
				dp[y][x][2] = min(dp[y - 1][x + 1][0], dp[y - 1][x + 1][1]) + arr[y][x];
			}
			else if (x == m - 1) {
				dp[y][x][0] = min(dp[y - 1][x - 1][1], dp[y - 1][x - 1][2]) + arr[y][x];
				dp[y][x][1] = dp[y - 1][x][0] + arr[y][x];
				dp[y][x][2] = INT_MAX;
			}
			else {
				dp[y][x][0] = min(dp[y - 1][x - 1][1], dp[y - 1][x - 1][2]) + arr[y][x];
				dp[y][x][1] = min(dp[y - 1][x][0], dp[y - 1][x][2]) + arr[y][x];
				dp[y][x][2] = min(dp[y - 1][x + 1][0], dp[y - 1][x + 1][1]) + arr[y][x];
			}
		}
	}
	int res = INT_MAX;
	for (int x = 0; x < m; x++)
		for (int d = 0; d < 3; d++)
			res = min(res, dp[n - 1][x][d]);
	cout << res << '\n';
	return 0;
}