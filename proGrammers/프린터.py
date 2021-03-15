# 프린터
from collections import deque

def solution(priorities, location):
    answer = 1
    dq = deque(priorities)
    while True:
        max_val = max(dq)
        val = dq.popleft()
        if val == max_val:
            if location == 0: break
            answer += 1
            location -= 1
        else:
            dq.append(val)
            if location == 0: location = len(dq)-1
            else: location -= 1
    return answer