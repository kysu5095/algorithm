// 세영이의 SEM력 연도

#include <stdio.h>

int main(){
    int test_case;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        int s, e, m;
        scanf("%d %d %d", &s, &e, &m);
        for(int i = 0; ; i += 365){
            int tmp = s + i;
            if((tmp - e) % 24 == 0 && (tmp - m) % 29 == 0){
                printf("#%d %d\n", tc, tmp);
                break;
            }
        }
    }
    return 0;
}