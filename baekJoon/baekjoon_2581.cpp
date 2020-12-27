#include <iostream>

using namespace std;

int arr[10001];

void eratos(const int& num){
    int i;
    for(i = 2; i <= num; i++){
        if(arr[i] != 0 && arr[i] != -1) break;
        else if(i == num) return;
    }
    arr[i] = 0;

    for(int j = 2; i * j <= num; j++){
        arr[i * j] = -1;
    }
    eratos(num);

    return;
}

int main(){
    for(int i = 0; i < 10001; i++){
        arr[i] = i;
    }
    eratos(10000);
    arr[1] = -1;

    int m, n, min;
    int cnt = 0;
    int sum = 0;
    int buf[10001];
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        if(arr[i] == 0){
             buf[cnt++] = i;
             sum += i;
        }
    }

    if(cnt == 0) cout << "-1\n";
    else{
        cout << sum << '\n';
        cout << buf[0] << '\n';
    }
    return 0;
}