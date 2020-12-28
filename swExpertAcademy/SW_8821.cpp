// 적고 지우기

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    bool jud[10];
    cin >> test_case;
    for(int tc = 1; tc <= test_case; tc++){
        string s;
        cin >> s;
        int len = s.size();
        int total = 0;
        memset(jud, false, sizeof(jud));
        for(int i = 0; i < len; i++){
            if(jud[s[i] - '0'] == false)
                total++;
            else
                total--;
            jud[s[i] - '0'] =! jud[s[i] - '0'];
        }
        cout << "#" << tc << " " << total << '\n';
    }
    return 0;
}