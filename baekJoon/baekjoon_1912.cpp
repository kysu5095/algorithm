// 연속합
// 4:40

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;
int arr[100001] = { 0, }, dp[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max_v = -INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	max_v = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		max_v = max(max_v, dp[i]);
	}
	cout << max_v << '\n';
	return 0;
}