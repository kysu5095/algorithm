# 다오의 데이트

import sys
from collections import deque
input = sys.stdin.readline

def bfs(arr, r, c, n, dq, command):
    idx = 0
    dy = {'W' : -1, 'A' : 0, 'S' : 1, 'D' : 0}
    dx = {'W' : 0, 'A' : -1, 'S' : 0, 'D' : 1}
    while dq and idx != n:
        sz = len(dq)
        while sz > 0:
            y, x, z = dq.popleft()
            sz -= 1
            for d in command[idx]:
                ny = y + dy[d]
                nx = x + dx[d]
                road = z[:]
                if ny < 0 or ny == r or nx < 0 or nx == c or arr[ny][nx] == '@': continue
                road.append(d)
                if arr[ny][nx] == 'Z': return road
                dq.append([ny, nx, road])

        idx += 1
    return []

r, c = map(int, input().split())
arr = [list(input().rstrip('\n')) for _ in range(r)]
n = int(input())
command = [list(map(str, input().split())) for _ in range(n)]

dq = deque()
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'D':
            dq.append([i, j, []])

res = bfs(arr, r, c, n, dq, command)
if len(res):
    print("YES")
    print(''.join(res))
else: print("NO")
