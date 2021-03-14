# 꿈틀꿈틀 호석 애벌레 - 기능성

import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

res = 0
def dfs(idx, cur_sum, energe):
    if idx == n:
        global res
        res = max(res, energe)
        return
    dfs(idx + 1, 0, energe)
    if cur_sum + arr[idx] >= k: dfs(idx + 1, 0, energe + cur_sum + arr[idx] - k)
    else: dfs(idx + 1, cur_sum + arr[idx], energe)

dfs(0, 0, 0)
print(res)
