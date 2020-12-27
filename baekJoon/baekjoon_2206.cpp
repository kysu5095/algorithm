//  벽 부수고 이동하기  //
////////////////////////

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int path = 1;
int visited[1000][1000][2];
string* arr;

class Point{    // 좌표 이동용 클래스
    public:
        int x, y;
};
Point p[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Wall{     // 해당 벽에대한 정보
    public:
        int x, y, check; // check == 0 >> 벽을 부순적 없음, check == 1 >> 벽을 부순적 있음
};
queue<Wall> q;

int bfs(){
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while(!q.empty()){
        int size = q.size();

        for(int j = 0; j < size; j++){
            int x = q.front().x;
            int y = q.front().y;
            int check = q.front().check;
            if(x == m - 1 && y == n - 1) return path;

            for(int i = 0; i < 4; i++){
                int nextX = x + p[i].x;
                int nextY = y + p[i].y;

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n){ // 해당 좌표가 범위 안에 있고
                    if(arr[nextY][nextX] == '0' && visited[nextY][nextX][check] != 1) { // 해당 좌표가 지나갈 수 있고 현제 루트의 check에서 지나간 적이 없다면 저장
                        q.push({nextX, nextY, check});
                        visited[nextY][nextX][check] = 1;
                    }

                    else if(arr[nextY][nextX] == '1' && check == 0){ // 그 좌표가 벽이지만 벽을 부순적이 없다면
                        q.push({nextX, nextY, 1});
                        visited[nextY][nextX][1] = 1;
                    }
                }
            }
            q.pop();
            if(q.size() == 0 && (x != m - 1 || y != n - 1)) return -1;
        }
        path++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr = new string[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // 판 만들기
    }

    if(n == 1 && m == 1) cout << 1 << '\n';
    else cout << bfs() << '\n';

    delete[] arr;
    return 0;
}