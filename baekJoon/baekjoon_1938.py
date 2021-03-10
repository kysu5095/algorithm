# 통나무 옮기기

import sys
from collections import deque
input = sys.stdin.readline

def isRight(n, arr, visited, y, x, flag):
    if visited[y][x][flag]: return False
    if flag == 0:
        for i in range(-1, 2, 1):
            nx = x + i
            if y < 0 or y == n or nx < 0 or nx == n or arr[y][nx] == '1': return False
    else:
        for i in range(-1, 2, 1):
            ny = y + i
            if ny < 0 or ny == n or x < 0 or x == n or arr[ny][x] == '1': return False
    return True

def bfs(n, arr, visited, y, x, flag1, fy, fx, flag2):
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    dq = deque()
    dq.append([y, x, flag1])
    t = 0
    while dq:
        sz = len(dq)
        while sz > 0:
            y, x, flag = dq.popleft()
            if y == fy and x == fx and flag == flag2: return t
            sz-=1
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if not isRight(n, arr, visited, ny, nx, flag): continue
                dq.append([ny, nx, flag])
                visited[ny][nx][flag] = True
            if visited[y][x][flag^1]: continue
            success = True
            for i in range(-1, 2, 1):
                for j in range(-1, 2, 1):
                    ny, nx = y + i, x + j
                    if ny < 0 or ny == n or nx < 0 or nx == n or arr[ny][nx] == '1':
                        success = False
                        break
                    if not success: break
            if not success: continue
            dq.append([y, x, flag^1])
            visited[y][x][flag^1] = True
        t += 1
    return 0

n = int(input())
arr = [list(map(str, input().rstrip('\n'))) for _ in range(n)]
visited = [[[False for _ in range(2)] for _ in range(n + 1)] for _ in range(n + 1)]
B = list()
E = list()
for i in range(n):
    for j in range(n):
        if arr[i][j] == 'B':
            B.append([i, j])
            arr[i][j] = '0'
        elif arr[i][j] == 'E':
            E.append([i, j])
            arr[i][j] = '0'
flag1 = 0
flag2 = 0
if B[0][0] != B[1][0]: flag1 = 1 # 세로
if E[0][0] != E[1][0]: flag2 = 1 # 세로
visited[B[1][0]][B[1][1]][flag1] = True
print(bfs(n, arr, visited, B[1][0], B[1][1], flag1, E[1][0], E[1][1], flag2))

