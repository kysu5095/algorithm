// 백만 장자 프로젝트

#include <cstdio>
#include <string.h>

int n;
long long result;
int arr[1000001];

int main(){

    int test_case;
    scanf("%d", &test_case);
    for(int tc = 0; tc < test_case; tc++){
        scanf("%d", &n);
        result = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int maxV = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(maxV < arr[i]) maxV = arr[i];
            else result += (maxV - arr[i]);
        }
        printf("#%d %lli\n", tc + 1, result);
    }

    return 0;
}