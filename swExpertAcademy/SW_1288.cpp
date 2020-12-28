// 새로운 불면증 치료법

#include <iostream>
#include <string.h>
 
using namespace std;
 
int test_case, n, res = 0;
bool jud[10] = { false, };
 
void cal(int n) {
    int tmp;
    int cnt = 1;
    int flag;
    while (true) {
        int val = n * cnt;
        res = val;
        cnt++;
        flag = 0;
        while (true) {
            if (val == 0) break;
            tmp = val % 10;
            jud[tmp] = true;
            val /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (!jud[i])
                flag++;
        }
        if (flag == 0) 
            return;
    }
}
 
int main() {
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> n;
        cal(n);
        cout << "#" << i + 1 << " " << res << '\n';
        memset(jud, false, sizeof(jud));
        res = 0;
    }
}