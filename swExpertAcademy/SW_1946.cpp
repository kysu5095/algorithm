// 간단한 압축 풀기

#include <iostream>
#include <string>

using namespace std;

int test_case, n, k;

int main(){
    cin >> test_case;
    for(int t = 0; t < test_case; t++){
        string str;
        int alpha_cnt = 0;
        char word;
        int cnt;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> word >> cnt;
            alpha_cnt += cnt;
            for(int j = 0; j < cnt; j++)
                str += word;
        }
        cout << "#" << t + 1 << '\n';
        for(int i = 0; i < alpha_cnt; i++){
            if(i % 10 == 0 && i != 0)
                cout << '\n';
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}