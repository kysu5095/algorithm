// 영준이와 신비한 뿔의 숲
 
#include <stdio.h>
 
int main(){
    int test_case, m, n;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf("%d", &n);
        scanf("%d", &m);
        printf("#%d %d %d\n", tc, (2 * m) - n, n - m);
    }
    return 0;
}