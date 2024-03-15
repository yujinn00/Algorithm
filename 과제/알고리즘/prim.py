import collections
import sys

def prim_mst(graph, start):
  visited[start] = 1
  mst = []

  while len(mst) < v - 1:
    min_weight = float('inf')
    min_edge = None

    for a in graph:
      if visited[a] == 1:
        for weight, b in graph[a]:
          if visited[b] == 0 and weight < min_weight:
            min_weight = weight
            min_edge = (a, b, weight)

    if min_edge:
      a, b, weight = min_edge
      visited[b] = 1
      mst.append((a, b, weight))

  return mst

v, e = map(int, sys.stdin.readline().split())
graph = collections.defaultdict(list)
visited = [0] * (v + 1)

for _ in range(e):
  a, b, weight = map(int, input().split())
  graph[a].append((weight, b))
  graph[b].append((weight, a))

mst = prim_mst(graph, 2)

for edge in mst:
  print(edge[0], edge[1], edge[2])