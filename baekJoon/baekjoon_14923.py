# 미로 탈출

import sys
from collections import deque
input = sys.stdin.readline

def bfs(n, m, y, x, fy, fx, arr, visited):
    dq = deque()
    dq.append([y, x, 0])
    visited[y][x][0] = True
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]

    t = 0
    while dq:
        t += 1
        sz = len(dq)
        while sz > 0:
            y, x, flag = dq.popleft()
            sz -= 1
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if ny == fy and nx == fx: return t
                if ny < 0 or ny == n or nx < 0 or nx == m or visited[ny][nx][flag]: continue
                if flag == 0:
                    if arr[ny][nx] == 0:
                        dq.append([ny, nx, flag])
                        visited[ny][nx][flag] = True
                    else:
                        if visited[ny][nx][1]: continue
                        dq.append([ny, nx, 1])
                        visited[ny][nx][1] = True
                else:
                    if arr[ny][nx] == 0:
                        dq.append([ny, nx, flag])
                        visited[ny][nx][flag] = True
                    else:
                        continue

    return -1

n, m = map(int, input().split())
y, x = map(int, input().split())
fy, fx = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[[False for _ in range(2)] for _ in range(m)] for _ in range(n)]
print(bfs(n, m, y-1, x-1, fy-1, fx-1, arr, visited))
