// 파스칼의 삼각형

#include <stdio.h>

using namespace std;

int main(){
    int test_case, n;
    int arr[11][11] = {{0, },};
    for(int i = 0; i < 11; i++){
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for(int i = 2; i < 11; i++)
        for(int j = 1; j < 10; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

    scanf("%d", &test_case);
    for(int test = 0; test < test_case; test++){
        scanf("%d", &n);
        printf("#%d\n", test + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}