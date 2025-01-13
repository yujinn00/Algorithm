import collections
from math import sqrt

def prim_mst(graph, start):
  visited = [False] * len(graph)
  visited[start] = True
  mst = []

  while len(mst) < len(graph) - 1:
    min_weight = float('inf')
    min_edge = None

    for node in range(len(graph)):
      if visited[node]:
        for weight, neighbor in graph[node]:
          if not visited[neighbor] and weight < min_weight:
            min_weight = weight
            min_edge = (node, neighbor, weight)

    if min_edge:
      node, neighbor, weight = min_edge
      visited[neighbor] = True
      mst.append((node, neighbor, weight))

  return mst

def approx_tsp(mst):
  edges = {}
  for start, dest, weight in mst:
    edges.setdefault(start, []).append((dest, weight))
    edges.setdefault(dest, []).append((start, weight))

  degree = [0] * len(edges)
  degree[0] = 1
  start = 0
  result = [0]

  while len(edges[start]) > 0:
    min_degree = float('inf')
    next_node = None

    for neighbor, weight in edges[start]:
      if degree[neighbor] < min_degree:
        min_degree = degree[neighbor]
        next_node = neighbor

    degree[next_node] += 1
    result.append(next_node)
    edges[start] = [(n, w) for n, w in edges[start] if n != next_node]
    start = next_node

  result = list(dict.fromkeys(result))
  result.append(0)
  return result

def get_graph():
  G = [[0, 3],
      [7, 5],
      [6, 0],
      [4, 3],
      [1, 0],
      [5, 3],
      [2, 2],
      [4, 1]]
  return G

def get_dist(path, graph):
  total = 0

  for i in range(len(path) - 1):
    start = graph[path[i]]
    end = graph[path[i + 1]]
    dist = sqrt((start[0] - end[0]) ** 2 + (start[1] - end[1]) ** 2)
    total += dist

  return total

graph_data = get_graph()
graph = {idx: coord for idx, coord in enumerate(graph_data)}

graph_status = collections.defaultdict(list)
for i, (x, y) in enumerate(graph_data):
  for j, (a, b) in enumerate(graph_data):
    if i != j:
      dist = sqrt((x - a) ** 2 + (y - b) ** 2)
      graph_status[i].append((dist, j))

mst = prim_mst(graph_status, 0)
tsp_path = approx_tsp(mst)

city_order = ''.join(chr(city + 65) for city in tsp_path)
print("이동 순서 :", city_order)
total = get_dist(tsp_path, graph)
print("이동 거리 :", total)
