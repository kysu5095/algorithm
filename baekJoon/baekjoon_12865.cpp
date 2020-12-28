// 평범한 배낭

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[101][2];
int dp[101][100001] = { {0,}, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - arr[i][0] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}