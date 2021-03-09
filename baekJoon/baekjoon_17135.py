import sys
import math
import copy
from itertools import combinations
input = sys.stdin.readline

n, m, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
case = list(combinations([i for i in range(m)], 3))
enermy = list()
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            enermy.append([True, i, j])

class ARCHER:
    def __init__(self):
        self.idx = 0
        self.d = float('inf')
        self.x = float('inf')

res = 0
for position in case:
    kill = 0
    v = copy.deepcopy(enermy)
    sz = len(v)
    while sz > 0:
        archer = [ARCHER() for _ in range(3)]
        for idx, node in enumerate(v):
            if node[0] == False: continue
            y, x = node[1], node[2]
            for i in range(3):
                dis = abs(y - n) + abs(x - position[i])
                if dis > d: continue
                if dis < archer[i].d or (dis == archer[i].d and x < archer[i].x):
                    archer[i].idx = idx
                    archer[i].d = dis
                    archer[i].x = x

        for i in range(3):
            if math.isinf(archer[i].d): continue
            if v[archer[i].idx][0] == False: continue
            v[archer[i].idx][0] = False
            sz-=1
            kill+=1

        for i, node in enumerate(v):
            if node[0] == False: continue
            v[i][1] += 1
            if v[i][1] == n:
                v[i][0] = False
                sz-=1

    res = max(res, kill)

print(res)

