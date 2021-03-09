# 싸지방에 간 준하

import sys
from collections import deque
from queue import PriorityQueue
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
arr.sort(key = lambda x : x[0])

cnt = 0
use = [0] * n
pq = PriorityQueue()
seat = PriorityQueue()
for start, end in arr:
    while not pq.empty():
        t, idx = pq.get()
        if t <= start:
            seat.put(idx)
        else:
            pq.put([t, idx])
            break
    if not seat.empty():
        seat_idx = seat.get()
        pq.put([end, seat_idx])
        use[seat_idx] += 1
    else:
        pq.put([end, cnt])
        use[cnt] += 1
        cnt += 1

print(cnt)
for i in range(cnt):
    print(use[i], end = ' ')
