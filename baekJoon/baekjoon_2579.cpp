// 계단 오르기

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[301];
int dp[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = max(arr[2], arr[1] + arr[2]);
	dp[3] = max(arr[3] + arr[1], arr[3] + arr[2]);
	for (int i = 4; i <= n; i++)
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	cout << dp[n] << '\n';
	return 0;
}