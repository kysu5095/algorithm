// 파핑파핑 지뢰찾기
 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <queue>
 
using namespace std;
 
int n, cnt, sec, total;
char arr[301][301];
bool visited[301][301];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
void bfs(int& _y, int& _x) {
    queue<pair<int, int>> q;
    q.push(make_pair(_y, _x));
    visited[_y][_x] = true;
    cnt++;
    int y, x, ny, nx;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
            if (arr[ny][nx] == '*') continue;
            if (arr[ny][nx] == '0') q.push(make_pair(ny, nx));
            visited[ny][nx] = true;
            cnt++;
        }
    }
}
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int test_case, ny, nx, num;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        cnt = 0;
        sec = 0;
        total = 0;
        memset(visited, false, sizeof(visited));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            for (int j = 0; j < n; j++)
                if (arr[i][j] == '.') total++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '.') {
                    num = 0;
                    for (int k = 0; k < 8; k++) {
                        ny = i + dy[k];
                        nx = j + dx[k];
                        if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
                        if (arr[ny][nx] == '*') num++;
                    }
                    arr[i][j] = num + '0';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '0' && !visited[i][j]) {
                    bfs(i, j);
                    sec++;
                }
            }
        }
        cout << "#" << tc << " " << total - cnt + sec << '\n';
    }
    return 0;
}