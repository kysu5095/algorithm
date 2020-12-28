// 농장 탈출 //
//////////////

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
 
using namespace std;
 
int n;
int maxCow = 1;
int tmpSum = 0;
int cowSum[21] = { 0, };
string str[21];
 
bool cal(int idx) {
    int tmpCnt = 0;
    for (int i = str[idx].size() - 1; i > -1; i--) {
        if (cowSum[tmpCnt] + str[idx][i] - '0' < 10) {
            tmpCnt++;
        }
        else {
            return false;
        }
    }
 
    tmpCnt = 0;
    for (int i = str[idx].size() - 1; i > -1; i--) {
        cowSum[tmpCnt] += str[idx][i] -'0';
        tmpCnt++;
    }
    return true;
}
 
void dfs(int cnt, int cow, int idx, bool *visited) {
    for (int i = idx; i < n; i++) {
        int tmpArr[21];
        for (int j = 0; j < 21; j++) {
            tmpArr[j] = cowSum[j];
        }
        if (!visited[i] && cal(i)) {
            maxCow = max(maxCow, cnt + 1);
            visited[i] = true;
            dfs(cnt + 1, cow, i + 1, visited);
            visited[i] = false;
            for (int j = 0; j < 21; j++) {
                cowSum[j] = tmpArr[j];
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    while (n > 0) {
        bool visited[21] = { false, };
        int cowSum[21] = { 0, };
        dfs(0, n, 0, visited);
        n--;
    }
    cout << maxCow << '\n';
 
    return 0;
}