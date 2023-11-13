from collections import deque
import sys

sys.setrecursionlimit(150000)

def bfs(start):
  global cnt
  queue = deque([start])
  visited[start] = cnt

  while queue:
    current = queue.popleft()
    graph[current].sort()

    for i in graph[current]:
      if visited[i] == 0:
        cnt += 1
        visited[i] = cnt
        queue.append(i)

n, m, r = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)
cnt = 1

for _ in range(m):
  u, v = map(int, sys.stdin.readline().split())
  graph[u].append(v)
  graph[v].append(u)

bfs(r)

for i in range(1, n + 1):
  print(visited[i])