// 시각 덧셈
 
#include <iostream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        int h1, m1, h2, m2, addM = 0;
        int resH, resM;
        cin >> h1 >> m1 >> h2 >> m2;
        if(m1 + m2 >= 60){
            addM = 1;
            resM = m1 + m2 -60;
        }
        else
            resM = m1 + m2;
        resH = h1 + h2 + addM;
        if(resH >= 13)
            resH -= 12;
        cout << "#" << i + 1 << " " << resH << " " << resM << endl;
    }
    return 0;
}