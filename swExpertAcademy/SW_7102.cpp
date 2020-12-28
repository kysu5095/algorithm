// 준홍이의 카드놀이

#include <stdio.h>
#include <string.h>
#include <algorithm>

int main(){
    int test_case, n, m, sum;
    int arr[41];
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        memset(arr, 0, sizeof(arr));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum = i + j;
                arr[sum]++;
            }
        }
        int maxV = -1;
        for(int i = 0; i < 41; i++)
            maxV = std::max(maxV, arr[i]);
        printf("#%d ", tc);
        for(int i = 0; i < 41; i++){
            if(arr[i] == maxV)
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}