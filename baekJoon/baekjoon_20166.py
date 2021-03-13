# 문자열 지옥에 빠진 호석

import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)
n, m, k = map(int, input().split())
arr = [list(input().rstrip('\n')) for _ in range(n)]
god = dict()
dy = [-1, -1, -1, 0, 1, 1, 1, 0]
dx = [-1, 0, 1, 1, 1, 0, -1, -1]

def dfs(y, x, idx):
    if idx == len(string): return 1
    res = 0
    for d in range(8):
        ny, nx = (y + n + dy[d]) % n, (x + m + dx[d]) % m
        if arr[ny][nx] == string[idx]:
            res += dfs(ny, nx, idx + 1)
    return res

for _ in range(k):
    string = str(input().rstrip('\n'))
    if string in god:
        print(god[string])
        continue
    res = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == string[0]:
                res += dfs(i, j, 1)
    god[string] = res
    print(res)
