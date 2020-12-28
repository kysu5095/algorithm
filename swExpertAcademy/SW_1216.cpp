// 3일차 - 회문2 //
//////////////////

#include <iostream>
#include <algorithm>

using namespace std;

char str[100][100];

int height(){   // 세로
    int maxLen = 0; // 지금까지 최대의 길이
    int cnt = 0;    // 현제 길이
    int end = 99;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k <= (end - j) / 2; k++){
                if(str[i + k][j] == str[end - k][j]){
                    if(j + k == end - k) cnt++;
                    else cnt += 2;
                }
                else{
                    end--;
                    cnt = 0;
                    break; // for문 종료
                }
            }
            maxLen = max(cnt, maxLen);
        }
    }

    return maxLen;
}

int width(){    // 가로
    int maxLen = 0;
    int cnt = 0;
    int end = 99;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k <= (end - j) / 2; k++){  // 내가 세웠는데도 아직도 이해 안됨
                if(str[i][j + k] == str[i][end - k]){
                    if(j + k == end - k) cnt++;
                    else cnt += 2;
                }
                else{
                    end--;
                    cnt = 0;
                    break; // for문 종료
                }
            }
            maxLen = max(cnt, maxLen);
        }
    }

    return maxLen;
}

int tile(void){
    return max(height(), width());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    char C;
    for(int i = 0; i < 10; i++){
        cin >> T;
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                cin >> C;
                str[j][k] = C;
            }
        }
        cout << "#" << T << " " << tile() <<'\n';
    }

    return 0;
}