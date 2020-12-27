#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[501][501];
int dp[501][501];
int n;

int triMax(const int& y, const int& x){
    if(y == n - 1) return arr[y][x];
    int& ret = dp[y][x];
    if(ret != -1) return ret;
    return ret = max(triMax(y + 1, x), triMax(y + 1, x + 1)) + arr[y][x];
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int Max = triMax(0, 0);
    cout << Max << '\n';
    
    return 0;
}