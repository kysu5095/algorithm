#include <iostream>
#include <cmath>

using namespace std;

int* arr;
/*
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
*/
void eratos(const int& num){
    int j;
    for(int i = 2; i < num; i++){
        if(arr[i] != 0 && arr[i] != -1){
            if((unsigned int)pow(i, 2) > 1000001) break;
            else{
                for(int j = (int)pow(i, 2); j < num;){
                    arr[j] = -1;
                    j = j + i;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    arr = new int[n + 1];

    for(int i = 2; i < n + 1; i++){
        arr[i] = i;
    }
    eratos(n + 1);
    arr[1] = -1;

    for(int i = m; i <= n; i++){
        if(arr[i] != -1){
             cout << i << '\n';
        }
    }

    return 0;
}