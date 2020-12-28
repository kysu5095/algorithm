// 아름이의 돌 던지기
 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
int test_case, n;
int idx1 = 0, idx2 = 0, cnt = 0;
int positive[1001] = { 0, };
int negative[1001] = { 0, };
 
bool desc(int a, int b) {
    return a > b;
}
 
int stone() {
    sort(positive, positive + idx1);
    sort(negative, negative + idx2, desc);
    int min_val = positive[0] < abs(negative[0]) ? positive[0] : abs(negative[0]);
    for (int i = 0; i < idx1; i++) {
        if (positive[i] != min_val) break;
        cnt++;
    }
    for (int i = 0; i < idx2; i++) {
        if (abs(negative[i]) != min_val) break;
        cnt++;
    }
    return min_val;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        cin >> n;
        int tmp;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp > 0)
                positive[idx1++] = tmp;
            else
                negative[idx2++] = tmp;
        }
        int min_val = stone();
        cout << "#" << i + 1 << " " << min_val << " " << cnt << endl;
        idx1 = 0, idx2 = 0, cnt = 0;
        memset(positive, 0, sizeof(positive));
        memset(negative, 0, sizeof(negative));
    }
    return 0;
}