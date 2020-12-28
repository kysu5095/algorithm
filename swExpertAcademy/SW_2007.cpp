// 패턴 마디의 길이

#include <iostream>
#include <string>
 
using namespace std;
 
int test_case, cnt;
string str;
 
void pattern(int n) {
    string tmp;
    for (int i = 0; i < n; i++) 
        tmp += str[i];
 
    int idx = 0;
    int size = tmp.size();
    while (idx + size < 30) {
        string compare;
        for (int i = idx; i < idx + size; i++)
            compare += str[i];
 
        if (tmp != compare)
            return;
 
        idx += size;
    }
    cnt = n;
}
 
int main() {
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> str;
        cnt = 0;
        for (int j = 1; i <= 10; j++) {
            pattern(j);
            if (cnt != 0)
                break;
        }
        cout << "#" << i + 1 << " " << cnt << '\n';
    }
}