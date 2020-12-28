// 쉬운 거스름돈

#include <stdio.h>

using namespace std;

int main(){
    int test_case, cost;
    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++){
        int arr[8] = {0, };
        scanf("%d", &cost);
        while(cost > 9){
            if(cost / 50000 > 0){
                arr[0]++;
                cost -= 50000;
                continue;
            }
            else if(cost / 10000 > 0){
                arr[1]++;
                cost -= 10000;
                continue;
            }
            else if(cost / 5000 > 0){
                arr[2]++;
                cost -= 5000;
                continue;
            }
            else if(cost / 1000 > 0){
                arr[3]++;
                cost -= 1000;
                continue;
            }
            else if(cost / 500 > 0){
                arr[4]++;
                cost -= 500;
                continue;
            }
            else if(cost / 100 > 0){
                arr[5]++;
                cost -= 100;
                continue;
            }
            else if(cost / 50 > 0){
                arr[6]++;
                cost -= 50;
                continue;
            }
            else if(cost / 10 >= 0){
                arr[7]++;
                cost -= 10;
                continue;
            }
        }
        printf("#%d\n", t + 1);
        for(int i = 0; i < 8; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}