/**************************************************************
    Problem: 1462
    User: kysu5095
    Language: C++
    Result: Success
    Time:119 ms
    Memory:2248 kb
****************************************************************/
 
// 보물섬
 
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int n, m, res = 0;
char arr[51][51];
bool visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
 
int bfs(int& _y, int& _x) {
    queue<pair<int, int>> q;
    q.push(make_pair(_y, _x));
    visited[_y][_x] = true;
    int y, x, ny, nx, len, cnt = 0;
    while (!q.empty()) {
        len = q.size();
        while (len--) {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
                if (visited[ny][nx] || arr[ny][nx] == 'W') continue;
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
        cnt++;
    }
    return cnt - 1;
}
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L') {
                memset(visited, false, sizeof(visited));
                int val = bfs(i, j);
                res = max(res, val);
            }
        }
    }
    cout << res << '\n';
    return 0;
}