// 피보나치 수 5

#include <iostream>
#include <string.h>

using namespace std;

int n;

int dp(int num) {
	if (num > 1) return (dp(num - 1) + dp(num - 2));
	else return num;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cout << dp(n) << '\n';
	return 0;
}