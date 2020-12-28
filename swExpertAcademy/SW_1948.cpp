// 날짜 계산기 //
////////////////

#include <iostream>
#include <string>
 
using namespace std;
 
string str[4];
 
int cal(int month) {
    switch (month)
    {
    case 0: return 0;
    case 1: return 31;
    case 2: return 59;
    case 3: return 90;
    case 4: return 120;
    case 5: return 151;
    case 6: return 181;
    case 7: return 212;
    case 8: return 243;
    case 9: return 273;
    case 10: return 304;
    case 11: return 334;
    case 12: return 365;
 
    default:
        break;
    }
}
 
int month() {
    int first, second;
    first = cal(stoi(str[0]) - 1) + stoi(str[1]);
    second = cal(stoi(str[2]) - 1) + stoi(str[3]);
 
    return second - first + 1;
}
 
int main() {
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> str[j];
        }
        cout << "#" << i + 1 << " " << month() << endl;
    }
 
    return 0;
}