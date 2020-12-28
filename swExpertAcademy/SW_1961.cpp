#include <iostream>
#include <string.h>
using namespace std;

int n, cnt = 0;
int arr1[8][8] = {{0, },};

void rotate(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << arr1[n - 1 - j][i];
        cout << " ";
        for(int j = 0; j < n; j++)
            cout << arr1[n - 1 - i][n - 1 - j];
        cout << " ";
        for(int j = 0; j < n; j++)
            cout << arr1[j][n - 1 - i];
        cout << endl;
    }
}

int main(){
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        cin >> n;
        memset(arr1, 0, sizeof(arr1));

        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                cin >> arr1[j][k];
        cout << "#" << i + 1 << endl;
        rotate();
    }
    return 0;
}