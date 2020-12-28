// 두 가지 빵의 딜레마

#include <stdio.h>

int main(){
    int test_case, a, b, c;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf("%d %d %d", &a, &b, &c);
        int cost = a < b ? a : b;
        printf("#%d %d\n", tc, c / cost);
    }
    return 0;
}