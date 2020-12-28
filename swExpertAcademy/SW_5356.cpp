// 의석이의 세로로 말해요

#include <stdio.h>
#include <string.h>

int main(){
    int test_case;
    char str[5][16];
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        memset(str, 0, sizeof(str));
        int len = 0;
        for(int i = 0; i < 5; i++){
            scanf("%s", str[i]);
            len = len < strlen(str[i]) ? strlen(str[i]) : len;
        }
        printf("#%d ", tc);
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 5; j++){
                if((int)str[j][i] != 0)
                    printf("%c", str[j][i]);
            }
        }
        printf("\n");
    }

    return 0;
}