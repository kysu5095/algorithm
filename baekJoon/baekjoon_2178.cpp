// 미로 탐색 //
//////////////

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
string* str;
bool visited[101][101] = {{false, }};

class Cordinate{
    public:
        int x, y;
};
Cordinate p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Point{
    public:
        int x, y, len;
};
queue<Point> q; // Point형 queue
Point start = {0, 0, 1}; // 처음 조건

int bfs(void){
    q.push(start);

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int len = q.front().len;

        if(x == m - 1 && y == n - 1){
            return len;
        }
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = x + p[i].x;
            int nextY = y + p[i].y;
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && str[nextY][nextX] == '1' && visited[nextY][nextX] == false){
                start = {nextX, nextY, len + 1};
                visited[nextY][nextX] = true;
                q.push(start);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    str = new string[n];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    visited[0][0] = true;
    cout << bfs() << '\n';
    delete[] str;

    return 0;
}