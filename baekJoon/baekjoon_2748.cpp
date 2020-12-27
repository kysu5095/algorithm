// 피보나치 연습 //
//////////////////

#include <iostream>
#include <cstring>        // for using memset

using namespace std;

long long int dp[91];     // dynamic programing
                          // by using long long format, avoid overflow
int fibonacci(int n){
    if(n == 0) return 0;  // initial condition
    if(n == 1) return 1;  // initial condition
    if(dp[n] != -1) return dp[n];  // memoization
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2); // recursive
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp)); // initialize dp
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';

    return 0;
}