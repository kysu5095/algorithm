// 홀수일까 짝수일까
#include <stdio.h>
#include <string.h>
int main(){
    int test_case;
    char arr[101];
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        scanf("%s", arr);
        int len = strlen(arr);
        if(arr[len - 1] % 2 == 0)
            printf("#%d Even\n", tc);
        else
            printf("#%d Odd\n", tc);
    }
    return 0;
}