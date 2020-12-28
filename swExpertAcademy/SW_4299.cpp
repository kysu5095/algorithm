// 태혁이의 사랑은 타이밍

#include <stdio.h>

int main(){
    int test_case, d, h, m;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf(" %d %d %d", &d, &h, &m);
        d = (d - 11) * 1440;
        h = h * 60;
        m = d + h + m - 671;
        if(m >= 0)
            printf("#%d %d\n", tc, m);
        else
            printf("#%d %d\n", tc, -1);
    }
    return 0;
}