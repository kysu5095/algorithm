// 앱

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, s = 0;
int mem[101], cost[101];
int dp[101][10001] = { {0,}, };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> mem[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		s += cost[i];
	}
	dp[0][cost[0]] = mem[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - cost[i] >= 0) 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
		}
	}
	for (int i = 0; i <= s; i++) {
		if (dp[n - 1][i] >= m) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}