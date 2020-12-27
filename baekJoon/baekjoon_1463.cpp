//1로 만들기

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}
	cout << arr[n] << '\n';
	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// int dp[1000001];
// int ll;

// int rec(int n){
//     int& ret = dp[n];
//     if(n == 1) return ret;
//     if(ret != ll) return ret;

//     if(n % 3 == 0) ret = min(ret, rec(n / 3) + 1);
//     if(n % 2 == 0) ret = min(ret, rec(n / 2) + 1);
//     ret = min(ret, rec(n - 1) + 1);

//     return ret;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     memset(dp, 1000001, sizeof(dp));
//     dp[0] = dp[1] = 0;
//     ll = dp[2];

//     cout << rec(n) << '\n';
//     return 0;
// }