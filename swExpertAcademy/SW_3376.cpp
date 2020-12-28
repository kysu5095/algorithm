// 파도반 수열

#include <stdio.h>

int main(){
    int test_case, n;
    long long arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= 100; i++)
        arr[i] = arr[i - 3] + arr[i - 2];
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf(" %d", &n);
        printf("#%d %lld\n", tc, arr[n]);
    }
    return 0;
}