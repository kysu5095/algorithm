# DFS와 BFS

import sys
from collections import deque

def dfs(v, visited, node):
	visited[node] = True
	print(node, end=' ')
	for i in v[node]:
		if not visited[i]:
			dfs(v, visited, i)

def bfs(v, visited, node):
	q = deque()
	q.append(start)
	visited[start] = True
	while q:
		node = q.popleft()
		print(node, end=' ')
		for i in v[node]:
			if not visited[i]:
				q.append(i)
				visited[i] = True

input = sys.stdin.readline
n, m, start = map(int, input().rstrip().split())

v = [[] for _ in range(n + 1)]
for _ in range (m):
	node1, node2 = map(int, input().rstrip().split())
	v[node1].append(node2)
	v[node2].append(node1)

for i in range (n + 1):
	v[i].sort()
visited = [False for _ in range(n + 1)]
dfs(v, visited, start)
print()
visited = [False for _ in range(n + 1)]
bfs(v, visited, start)