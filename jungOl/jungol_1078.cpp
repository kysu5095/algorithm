/**************************************************************
    Problem: 1078
    User: kysu5095
    Language: C++
    Result: Success
    Time:3 ms
    Memory:1296 kb
****************************************************************/
 
// 저글링 방사능 오염
 
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <string.h>
 
using namespace std;
 
int n, m, cnt = 0;
bool arr[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
 
int bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    cnt--;
    int y, x, ny, nx, len, sec = 2;
    while (!q.empty()) {
        sec++;
        len = q.size();
        while (len--) {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i];
                nx = x + dx[i];
                if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
                if (!arr[ny][nx]) continue;
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                cnt--;
            }
        }
    }
    return sec;
}
 
int main() {
    int sy, sx;
    memset(visited, false, sizeof(visited));
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1d", &arr[i][j]);
            if (arr[i][j]) cnt++;
        }
    }
    scanf("%d %d", &sx, &sy);
    printf("%d\n", bfs(sy - 1, sx - 1));
    printf("%d\n", cnt);
    return 0;
}