// 1, 2, 3 더하기

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	int dp[12];
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		cout << dp[n] << '\n';
	}
	return 0;
}