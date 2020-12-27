#include <iostream>

using namespace std;

int arr[1001];

void eratos(int num){
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
    for(int i = 0; i < 1001; i++){
        arr[i] = i;
    }

    eratos(1000);
    arr[1] = -1;

    int n, input;
    int count = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        arr[input] == 0 ? count++ : 0;
    }

    cout << count << '\n';
    return 0;
}