// 건초더미

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <algorithm>

int main() {
   int test_case, n;
   int arr[10001];
   scanf("%d", &test_case);
   for (int tc = 1; tc <= test_case; tc++) {
      int sum = 0, res = 0;
      scanf(" %d", &n);
      for (int i = 0; i < n; i++) {
         scanf(" %d", &arr[i]);
         sum += arr[i];
      }
      sum /= n;
      for (int i = 0; i < n; i++)
         res += abs(sum - arr[i]);
      printf("#%d %d\n", tc, res / 2);
   }
   return 0;
}