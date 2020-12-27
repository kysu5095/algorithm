// 외판원 순회

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string.h>

using namespace std;
const int INF = 1e9;
int n;
int arr[16][16];
int dp[16][1 << 16];

int func(int cur, int route) {
	if (route == (1 << n) - 1) {
		if (arr[cur][0]) return arr[cur][0];
		else return INF;
	}
	int& ref = dp[cur][route];
	if (ref) return ref;
	ref = INF;

	for (int i = 0; i < n; i++) {
		if (arr[cur][i] && !(route & (1 << i)))
			ref = min(ref, func(i, route | (1 << i)) + arr[cur][i]);
	}
	return ref;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	memset(dp, 0, sizeof(dp));
	cout << func(0, 1) << '\n';
	return 0;
}