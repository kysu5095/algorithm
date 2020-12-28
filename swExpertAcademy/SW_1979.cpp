// 어디에 단어가 들어갈 수 있을까

#include <iostream>
#include <string.h>
 
using namespace std;
 
int test_case, n, k, res;
int arr[16][16];
 
void find() {
    // 가로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - k; j++) {
            if (arr[i][j] == 0) continue;
            int cnt = 1;
            int x = j + 1;
            while (cnt != k) {
                if (arr[i][x] == 0) break;
                cnt++;
                x++;
            }
            if (cnt == k) {
                if (j != 0) {
                    if (arr[i][j - 1] == 1)
                        continue;
                }
                // 배열의 끝일 경우
                if (x == n) 
                    res++;
                // 다음칸에 벽돌일 경우
                else {
                    if (arr[i][x] == 0) 
                        res++;
                }
            }
        }
    }
    // 세로
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n - k; i++) {
            if (arr[i][j] == 0) continue;
            int cnt = 1;
            int y = i + 1;
            while (cnt != k) {
                if (arr[y][j] == 0) break;
                cnt++;
                y++;
            }
            if (cnt == k) {
                if (i != 0) {
                    if (arr[i - 1][j] == 1)
                        continue;
                }
                // 배열의 끝일 경우
                if (y == n)
                    res++;
                // 다음칸에 벽돌일 경우
                else {
                    if (arr[y][j] == 0)
                        res++;
                }
            }
        }
    }
}
 
int main() {
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        res = 0;
        memset(arr, -1, sizeof(arr));
        cin >> n >> k;
        for (int j = 0; j < n; j++) 
            for (int k = 0; k < n; k++)
                cin >> arr[j][k];
 
        find();
        cout << "#" << i + 1 << " " << res << '\n';
    }
}