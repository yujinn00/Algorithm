import sys

def dfs(start):
  visited[start] = 1

  for i in graph[start]:
    if visited[i] == 0:
      dfs(i)

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)

for _ in range(m):
  u, v = map(int, sys.stdin.readline().split())
  graph[u].append(v)
  graph[v].append(u)

dfs(1)

print(sum(visited) - 1)