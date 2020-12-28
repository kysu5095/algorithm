// 현주의 상자 바꾸기
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 
int main() {
    int test_case, n, q, l, r;
    int arr[1005];
    scanf("%d", &test_case);
    for (int tc = 1; tc <= test_case; tc++) {
        memset(arr, 0, sizeof(arr));
        scanf(" %d %d", &n, &q);
        for (int i = 1; i <= q; i++) {
            scanf(" %d %d", &l, &r);
            for (int j = 0; j < r - l + 1; j++)
                arr[l + j] = i;
        }
        printf("#%d ", tc);
        for (int i = 1; i <= n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}