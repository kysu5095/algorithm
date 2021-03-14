# 골목 대장 호석 - 기능성

import sys
from queue import PriorityQueue
input = sys.stdin.readline

def bfs():
    pq = PriorityQueue()
    pq.put([0, A, 0])
    visited[A] = 0
    while not pq.empty():
        cost, node, max_val = pq.get()
        if node == B:
            res.append(max_val)
            continue
        if cost > visited[node]: continue
        for next, next_cost in v[node]:
            if cost + next_cost > C: continue
            if cost + next_cost >= visited[next]: continue
            pq.put([cost + next_cost, next, max(max_val, next_cost)])
            visited[next] = cost + next_cost

n, m, A, B, C = map(int, input().split())
v = [[] for _ in range(n + 1)]
visited = [float('inf') for _ in range(n + 1)]
res = list()
for _ in range(m):
    node1, node2, distance = map(int, input().split())
    v[node1].append([node2, distance])
    v[node2].append([node1, distance])

bfs()
if len(res) == 0: print(-1)
else: print(min(res))