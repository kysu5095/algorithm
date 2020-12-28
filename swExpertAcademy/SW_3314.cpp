// 보충학습과 평균

#include <stdio.h>

int main(){
    int test_case, input, sum;
    scanf("%d", &test_case);
    for(int tc = 1; tc <= test_case; tc++){
        sum = 0;
        for(int i = 0; i < 5; i++){
            scanf("%d", &input);
            if(input < 40)
                sum += 40;
            else
                sum += input;
        }
        printf("#%d %d\n", tc, sum / 5);
    }
    return 0;
}