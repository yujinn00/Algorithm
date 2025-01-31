import sys

sys.setrecursionlimit(150000)

def dfs(start):
  global cnt
  visited[start] = cnt
  graph[start].sort()

  for i in graph[start]:
    if visited[i] == 0:
      cnt += 1
      dfs(i)

n, m, r = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)
cnt = 1

for _ in range(m):
  u, v = map(int, sys.stdin.readline().split())
  graph[u].append(v)
  graph[v].append(u)

dfs(r)

for i in range(1, n + 1):
  print(visited[i])