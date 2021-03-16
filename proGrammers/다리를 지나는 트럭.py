from collections import deque

def solution(bridge_length, weight, truck_weights):
    t = 0
    w = 0
    waiting = deque(truck_weights)
    bridge = deque(0 for _ in range(bridge_length))
    while bridge:
        t += 1
        w -= bridge.pop()
        if waiting:
            if w + waiting[0] <= weight:
                w += waiting[0]
                bridge.appendleft(waiting.popleft())
            else: 
                bridge.appendleft(0)
    return t