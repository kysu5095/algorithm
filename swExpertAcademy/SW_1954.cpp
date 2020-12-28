// 달팽이 숫자

#include <iostream>
#include <string.h>

using namespace std;

int n;
int arr [11][11] = {{0, },};

class Point{
    public:
        int y, x;
};
Point p[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void snail(){
    int y = 0, x = 0;
    int cnt = 2, idx = 0;
    arr[y][x] = 1;
    
    while(true){
        if(idx == 4)
            idx = 0;

        int ny = y + p[idx].y;
        int nx = x + p[idx].x;
        if(ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] == 0){
            y = ny, x = nx;
            arr[ny][nx] = cnt++;
        }
        else{
            if(arr[y + p[(idx + 1) % 4].y][x + p[(idx + 1) % 4].x] != 0)
                break;

            idx++; 
        }       
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        cin >> n;

        snail();
        cout << "#" << i + 1 << endl;
        print();
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}