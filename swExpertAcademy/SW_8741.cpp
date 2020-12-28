// 두문자어

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin >> test_case;
    for(int tc = 1; tc <= test_case; tc++){
        string s;
        cout << "#" << tc << " ";
        for(int i = 0; i < 3; i++){
            cin >> s;
            cout << char(s[0] - 32);
        }
        cout << '\n';
    }

    return 0;
}