//  토마토  //
/////////////

#include <iostream>
#include <queue>

using namespace std;

int m, n;
int unTomato = 0;
int arr[1000][1000] = { {2, }};
bool visited[1000][1000] = { {false, }};

class Point{
    public:
        int x, y;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<Point> q;

bool isFull(void){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1) cnt++;
        }
    }
    return cnt == (m * n - unTomato);
}

int dfs(void){
    int day = 0;
    while(!q.empty()){
        int size = q.size();
        for(int j = 0; j < size; j++){
            int x = q.front().x;
            int y = q.front().y;
            visited[y][x] = true;
            for(int i = 0; i < 4; i++){
                int nextX = x + p[i].x;
                int nextY = y + p[i].y;

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && arr[nextY][nextX] == 0 && visited[nextY][nextX] == false){
                    q.push({nextX, nextY});
                    visited[nextY][nextX] = true;
                    arr[nextY][nextX] = 1;
                }
            }
            q.pop();
        }
        if(q.size() == 0 && isFull()) return day;
        else if(q.size() == 0 && !isFull()) return -1;
        
        day++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int input;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input;
            arr[i][j] = input;
            if(input == 1) q.push({j, i});
            if(input == -1) unTomato++;
        }
    }
    if(q.size() == m * n - unTomato) cout << 0 << '\n';
    else cout << dfs() << '\n';

    return 0;
}