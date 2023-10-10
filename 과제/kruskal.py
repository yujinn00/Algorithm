import sys

def find_parent(parent, a):
  if parent[a] != a:
    parent[a] = find_parent(parent, parent[a])
  return parent[a]

def union_parent(parent, a, b):
  a = find_parent(parent, a)
  b = find_parent(parent, b)

  if a < b:
    parent[b] = a
  else:
    parent[a] = b

def kruskal_mst(graph, n):
  edges = [(weight, a, b) for a, b, weight in graph]
  edges.sort()

  parent = [i for i in range(n + 1)]
  mst = []

  for edge in edges:
    weight, a, b = edge

    if find_parent(parent, a) != find_parent(parent, b):
      union_parent(parent, a, b)
      mst.append((a, b, weight))

  return mst

v, e = map(int, sys.stdin.readline().split())
graph = []

for _ in range(e):
  a, b, weight = map(int, sys.stdin.readline().split())
  graph.append((a, b, weight))

mst = kruskal_mst(graph, v)

for edge in mst:
  print(edge[0], edge[1], edge[2])