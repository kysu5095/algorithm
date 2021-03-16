import sys
from itertools import permutations
sys.setrecursionlimit(100000000)

n = 10000000
arr = [True for _ in range(0, n+1)]

def eratos():
    for i in range(2, int(n**0.5)+1):
        if not arr[i]: continue
        for j in range(i+i, n, i):
            arr[j] = False

def solution(numbers):
    answer = 0
    eratos()
    per_list = list()
    for i in range(1, len(numbers)+1):
        per = list(permutations(numbers, i))
        for node in per:
            per_list.append(''.join(node))
    s = list(set(int(x) for x in per_list))
    if 0 in s: s.remove(0)
    if 1 in s: s.remove(1)
    for node in s:
        if arr[node]: answer += 1
    return answer