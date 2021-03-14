# 골목 대장 호석 - 기능성

import sys
from queue import PriorityQueue
input = sys.stdin.readline

n, m, A, B, C = map(int, input().split())
v = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
res = list()
for _ in range(m):
    node1, node2, distance = map(int, input().split())
    v[node1].append([node2, distance])
    v[node2].append([node1, distance])

def dfs(node, cost, max_val):
    if node == B:
        res.append(max_val)
        return
    for next, next_cost in v[node]:
        if visited[next]: continue
        if cost + next_cost > C: continue
        visited[next] = True
        dfs(next, cost + next_cost, max(max_val, next_cost))
        visited[next] = False

visited[A] = True
dfs(A, 0, 0)

if len(res) == 0: print(-1)
else: print(min(res))