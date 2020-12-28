// 중간 평균값 구하기

#include <cstdio>
#include <string.h>

using namespace std;

int arr[101] = {0, };
int main(){
    int test_case, n, val;
    scanf("%d", &test_case);
    for(int t = 0; t < test_case; t++){
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < 1000; i++){
            scanf("%d", &val);
            arr[val]++;
        }
        int max = -1;
        int max_val;
        for(int i = 0; i < 101; i++){
            if(max <= arr[i]){
                max = arr[i];
                max_val = i;
            }
        }
        
        printf("#%d %d\n", n, max_val);
    }
    return 0;
}


