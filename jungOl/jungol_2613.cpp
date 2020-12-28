/**************************************************************
    Problem: 2613
    User: kysu5095
    Language: C++
    Result: Success
    Time:144 ms
    Memory:7396 kb
****************************************************************/
 
// 토마토(고)
 
#include <iostream>
#include <queue>
 
using namespace std;
 
int n, m, cnt = 0;
int arr[1001][1001];
bool visited[1001][1001] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;
 
int bfs() {
    if (cnt == 0) return 0;
    int y, x, ny, nx, len, sec = 0;
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
                if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
                if (visited[ny][nx] || arr[ny][nx] == -1) continue;
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                cnt--;
            }
        }
        if (cnt == 0) return sec;
    }
    return -1;
}
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) cnt++;
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    cout << bfs() << '\n';
    return 0;
}