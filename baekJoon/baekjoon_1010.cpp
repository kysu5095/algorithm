// 다리 놓기

#include <iostream>
#include <string.h>

using namespace std;

int test_case, n, m;
int dp[31][31];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i <= m; i++)
			dp[1][i] = i;
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = j; k >= i; k--) {
					dp[i][j] += dp[i - 1][k - 1];
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}