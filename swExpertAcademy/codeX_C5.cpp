// 건물세우기 //
///////////////

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n;
int arr[11][11] = { {0, }, };
bool visited[11] = { false };
int res[11] = { 0, };
int maxSum = 20000000;
 
void dfs(int cnt) {
    if (cnt == n) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += arr[i][res[i]];
        }
        maxSum = min(maxSum, tmp);
    }
 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            res[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << maxSum << '\n';
 
    return 0;
}