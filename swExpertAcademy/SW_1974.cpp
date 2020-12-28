// 스도쿠 검증

#include <iostream>
#include <string.h>

using namespace std;

int arr[9][9] = {{0,},};

bool sudocu1(){
    // 3 * 3 확인
    for(int j = 0; j < 9; j += 3){
        for(int k = 0; k < 9; k += 3){
            int tmp = 0;
            for(int l = j; l < j + 3; l++){
                for(int m = k; m < k + 3; m++){
                    tmp += arr[l][m];
                }
            }
            if(tmp != 45)
                return false;
        }
    }
    return true;
}

bool sudocu2(){
    // 가로 * 세로 확인
    int tmp = 0;
    for(int i = 0; i < 9; i++){
        tmp = 0;
        for(int j = 0; j < 9; j++)
            tmp += arr[i][j];
        
        if(tmp != 45)
            return false;
        tmp = 0;

        for(int j = 0; j < 9; j++)
            tmp +=arr[j][i];

        if(tmp != 45)
            return false;
    }
    return true;
}

int main(){
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                cin >> arr[j][k];

        bool flag = false;
        if(sudocu1()){
            if(sudocu2()){
                flag = true;
            }
        }
        if(flag == true)
            cout << "#" << i + 1 << " 1" << endl;
        else
            cout << "#" << i + 1 << " 0" << endl;
        
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}