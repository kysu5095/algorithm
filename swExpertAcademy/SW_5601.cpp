// 쥬스 나누기

#include<stdio.h>

int main(){
    int test_case, n;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf("%d", &n);
        printf("#%d ", tc);
        for(int i = 0; i < n; i++)
            printf("1/%d ", n);
        printf("\n");
    }
    return 0;
}