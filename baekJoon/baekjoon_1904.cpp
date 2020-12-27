#include <iostream>

using namespace std;
const int MOD = 15746;

int dp[10000001];

int rec(int n){
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0);

    int n;
    cin >> n;
    cout << rec(n) << endl;

    return 0;
}