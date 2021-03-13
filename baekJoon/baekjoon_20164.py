# 홀수 홀릭 호석

import sys
input = sys.stdin.readline
N = str(input().rstrip('\n'))
max_v = float('-inf')
min_v = float('inf')

def dfs(n, s):
    cnt = 0
    for idx in n:
        if int(idx) % 2 == 1:
            cnt += 1
    if len(n) == 1:
        global max_v, min_v
        max_v = max(max_v, s + cnt)
        min_v = min(min_v, s + cnt)
        return
    if len(n) == 2:
        next = int(n[0]) + int(n[1])
        dfs(str(next), s + cnt)
        return
    else:
        for i in range(1, len(n) - 1):
            for j in range(i + 1, len(n)):
                next1 = int(n[:i])
                next2 = int(n[i:j])
                next3 = int(n[j:])
                dfs(str(next1 + next2 + next3), s + cnt)

dfs(N, 0)
print(min_v, max_v)