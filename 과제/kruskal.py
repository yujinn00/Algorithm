import sys

def find_parent(parent, x):
  if parent[x] != x:
    parent[x] = find_parent(parent, parent[x])
  return parent[x]

def union_parent(parent, a, b):
  a = find_parent(parent, a)
  b = find_parent(parent, b)

  if a < b:
    parent[b] = a
  else:
    parent[a] = b

def kruskal_mst(graph, n):
  edges = [(cost, a, b) for a, b, cost in graph]
  edges.sort()

  parent = [i for i in range(n + 1)]
  minimum_spanning_tree = []

  for edge in edges:
    cost, a, b = edge

    if find_parent(parent, a) != find_parent(parent, b):
      union_parent(parent, a, b)
      minimum_spanning_tree.append((a, b, cost))

  return minimum_spanning_tree

v, e = map(int, sys.stdin.readline().split())
graph = []

for _ in range(e):
  a, b, cost = map(int, sys.stdin.readline().split())
  graph.append((a, b, cost))

minimum_spanning_tree = kruskal_mst(graph, v)

for edge in minimum_spanning_tree:
  print(edge[0], edge[1], edge[2])

# 크루스칼 알고리즘은 간선을 가중치 순으로 정렬하기 때문에,
# 간선의 개수에 따라 효율적으로 동작합니다.
# 그래프의 간선 개수가 많을 때 유용합니다.

# https://8iggy.tistory.com/160