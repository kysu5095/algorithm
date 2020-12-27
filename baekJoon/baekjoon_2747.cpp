#include <iostream>

using namespace std;

int dp[46]{0, };

int recur(int n){
    if(n == 1 || n == 2) return 1;
    if(dp[n] != 0) return dp[n];
    else return dp[n] = recur(n - 1) + recur(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << recur(n) << '\n';

    return 0;
}