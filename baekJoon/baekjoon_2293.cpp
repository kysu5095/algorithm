// 동전 1
// 4:00

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int arr[101];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}