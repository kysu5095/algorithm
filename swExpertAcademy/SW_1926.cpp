// 간단한 369 게임

#include <stdio.h>

using namespace std;

int main(){
    int n, tmp;
    bool flag = false;
    int arr[1001];
    for(int i = 0; i < 1001; i++)
        arr[i] = i;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        tmp = arr[i];
        flag = false;
        while(tmp > 0){
            if((tmp % 10) != 0 && (tmp % 10) % 3 == 0){
                flag = true;
                printf("-");
            }
            tmp /= 10;
        }
        if(flag == false)
            printf("%d ", arr[i]);
        else
            printf(" ");
    }
}