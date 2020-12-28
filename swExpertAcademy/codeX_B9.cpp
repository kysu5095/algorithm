// 저글링 방사능 오염 //
//////////////////////

#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
 
int n, m;
int leftZ = 0;
int second;
bool visited[101][101] = { {false, }, };
string str[101];
 
class Point {
public:
    int x, y, sec;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<Point> q;
 
void virus() {
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int sec = q.front().sec;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + p[i].x;
            int ny = y + p[i].y;
 
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && (str[ny][nx] - '0' == 1) && !visited[ny][nx]) {
                visited[ny][nx] = true;
                leftZ--;
                q.push({ nx, ny , sec + 1});
            }
        }
        second = q.front().sec + 3;
        q.pop();
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (int j = 0; j < m; j++) {
            if (str[i][j] -'0' == 1) leftZ++;
        }
    }
 
    int x, y;
    cin >> x >> y;
    q.push({ x - 1, y - 1, 0 });
    visited[y - 1][x - 1] = true;
    leftZ--;
 
    virus();
    cout << second << '\n';
    cout << leftZ << '\n';
 
    return 0;
}