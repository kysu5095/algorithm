// 쉬운 계단 수

#include <cstdio>

using namespace std;

int main() {
    int ans = 0;
    int N, i, j;
    int dp[100][12] = { 0 };
    scanf("%d", &N);

    for (i = 2; i < 11; i++) dp[0][i] = 1;

    for (i = 1; i < N; i++) {
        dp[i][0] = 0;
        dp[i][11] = 0;
        for (j = 1; j < 11; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    for (i = 1; i < 11; i++) {
        ans = (ans + dp[N-1][i]) % 1000000000;
    }

    printf("%d\n", ans);

    return 0;
}