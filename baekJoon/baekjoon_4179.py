import sys
import math
from collections import deque
input = sys.stdin.readline

def bfs(r, c, arr, dq, fire, visited):
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    t = 0
    while dq:
        t += 1
        sz = len(fire)
        while sz > 0:
            y, x = fire.popleft()
            sz -= 1
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < r and 0 <= nx < c and arr[ny][nx] == '.':
                    fire.append([ny, nx])
                    arr[ny][nx] = 'F'

        sz = len(dq)
        while sz > 0:
            y, x = dq.popleft()
            sz -= 1
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or ny == r or nx < 0 or nx == c: return t
                if visited[ny][nx] or arr[ny][nx] == '#' or arr[ny][nx] == 'F': continue
                dq.append([ny, nx])
                visited[ny][nx] = True

    return float('inf')

r, c = map(int, input().split())
arr = [list(input().rstrip('\n')) for _ in range(r)]
visited = [[False for _ in range(c)] for _ in range(r)]

dq = deque()
fire = deque()
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'J':
            dq.append([i, j])
            visited[i][j] = True
            arr[i][j] = '.'
        elif arr[i][j] == 'F': fire.append([i, j])

res = bfs(r, c, arr, dq, fire, visited)
if math.isinf(res): print("IMPOSSIBLE")
else: print(res)