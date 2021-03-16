import sys
sys.setrecursionlimit(100000000)
from collections import deque

def separate(w):
    l = 0
    r = 0
    for i in range(len(w)):
        if w[i] == '(': l+=1
        else: r+=1
        if l==r: return w[:i+1], w[i+1:]

def isRight(w):
    dq = deque()
    for node in w:
        if node == '(': dq.append(node)
        else:
            if not dq: return False
            dq.pop()
    return True

def solution(p):
    if not p: return ''
    u, v = separate(p)
    if isRight(u): return u + solution(v)
    else:
        tmp = '('
        tmp += solution(v)
        tmp += ')'
        for i in range(1, len(u)-1):
            if u[i] == '(': tmp += ')'
            else: tmp += '('
    return tmp