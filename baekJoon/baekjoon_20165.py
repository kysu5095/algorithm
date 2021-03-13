# 인내의 도미노 장인 호석

import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

res = 0
def game(y, x, d):
    global n, m, arr, res
    dy = {'E':0, 'W':0, 'S':1, 'N':-1}
    dx = {'E':1, 'W':-1, 'S':0, 'N':0}
    if d is not None:
        if arr[y][x] > 10: return
        cnt = arr[y][x]
        while cnt > 0:
            if cnt < arr[y][x] < 10: cnt = arr[y][x]
            if arr[y][x] < 10:
                arr[y][x] += 10
                res += 1
            y += dy[d]
            x += dx[d]
            if y < 0 or y == n or x < 0 or x == m: return
            cnt -= 1

    else:
        if arr[y][x] < 10: return
        arr[y][x] -= 10

for i in range(r * 2):
    if i % 2 == 0:
        y, x, d = input().split()
        game(int(y)-1, int(x)-1, d)
    else:
        y, x = map(int, input().split())
        game(int(y)-1, int(x)-1, None)

print(res)
for i in range(n):
    for j in range(m):
        if arr[i][j] < 10: print('S', end=' ')
        else: print('F', end=' ')
    print()