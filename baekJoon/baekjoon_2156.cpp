// 포도주 시식
// 4:10

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = max(arr[2], arr[1] + arr[2]);
	dp[3] = max(arr[3] + dp[1], arr[3] + arr[2]);
	dp[3] = max(dp[3], dp[2]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n] << '\n';
	return 0;
}