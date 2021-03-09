import sys
from collections import deque

input = sys.stdin.readline

def convey_move(n, dq):
    if dq[n-1][0]: dq[n-1][0] = False
    dq.appendleft(dq.pop())

def robot_move(n, dq):
    cnt = 0
    if dq[n-1][0]: dq[n-1][0] = False
    for idx in range(n-2, -1, -1):
        if dq[idx][0] and dq[idx+1][0] == False and dq[idx+1][1] > 0:
            dq[idx][0] = False
            dq[idx+1][0] = True
            dq[idx+1][1] -= 1
            if dq[idx+1][1] == 0: cnt+=1
    return cnt

def on_robot(n, dq):
    cnt = 0
    if dq[0][0] == False and dq[0][1] > 0:
        dq[0][0] = True
        dq[0][1] -= 1
        if dq[0][1] == 0: cnt+=1
    return cnt

def convey(n, k, dq):
    turn = 0
    while True:
        turn+=1
        convey_move(n, dq)
        k -= robot_move(n, dq)
        if k <= 0: break
        k -= on_robot(n, dq)
        if k <= 0: break
    return turn

n, k = map(int, input().split())
arr = list(map(int, input().split()))
dq = deque()
for val in arr:
    dq.append([False, val])
print(convey(n, k, dq))

