//  토마토2  //
//////////////

#include <iostream>
#include <queue>

using namespace std;

int m, n, h;
int unTomato = 0;
int arr[100][100][100] = { { {2, } } };
bool visited[100][100][100] = { { { false, } } };

class Point{
    public:
        int h, x, y;
};
Point p[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<Point> q;

bool isFull(){
    int cnt = 0;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[k][i][j] == 1) cnt++;
            }
        }
    }
    return cnt == m * n * h - unTomato;
}

int bfs(void){
    int day = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int preX = q.front().x;
            int preY = q.front().y;
            int preH = q.front().h;
            visited[preH][preY][preX] = true;

            for(int j = 0; j < 6; j++){
                int nextX = preX + p[j].x;
                int nextY = preY + p[j].y;
                int nextH = preH + p[j].h;

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && nextH >= 0 && nextH < h){
                    if(arr[nextH][nextY][nextX] == 0 && visited[nextH][nextY][nextX] == false){
                        q.push({nextH, nextX, nextY});
                        visited[nextH][nextY][nextX] = true;
                        arr[nextH][nextY][nextX] = 1;
                    }
                }
            }
            q.pop();
        }
        if(q.size() == 0 && isFull()) return day;
        if(q.size() == 0 && !isFull()) return -1;

        day++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int input;
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> input;
                arr[k][i][j] = input;
                if(input == 1) q.push({k, j, i});
                if(input == -1) unTomato++;
            }
        }
    }

    if(q.size() == m * n * h - unTomato) cout << 0 << '\n';
    else cout << bfs() << '\n';

    return 0;
}