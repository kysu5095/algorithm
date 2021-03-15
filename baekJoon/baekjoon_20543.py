# 폭탄 던지는 태영이

import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
res = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr[i][j] *= -1
r = m // 2
for i in range(r, n-r):
    for j in range(r, n-r):
        res[i][j] = arr[i-r][j-r]
        if i-r-1 >= 0: res[i][j] -= arr[i-r-1][j-r]
        if j-r-1 >= 0: res[i][j] -= arr[i-r][j-r-1]
        if i-r-1 >= 0 and j-r-1 >= 0: res[i][j] += arr[i-r-1][j-r-1]
        if i-m >= 0: res[i][j] += res[i-m][j]
        if j-m >= 0: res[i][j] += res[i][j-m]
        if i-m >= 0 and j-m >= 0: res[i][j] -= res[i-m][j-m]

for i in range(n):
    for j in range(n):
        print(res[i][j], end = ' ')
    print()