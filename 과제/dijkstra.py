import heapq
import timeit

def AllPairsShortest(G, s):
  n, edges = G

  D = [float('inf')] * n
  D[s] = 0

  pq = [(0, s)]

  while pq:
    dist_v, v = heapq.heappop(pq)

    if D[v] < dist_v:
      continue

    for u, weight in edges[v]:
      new_dist = D[v] + weight

      if new_dist < D[u]:
        D[u] = new_dist
        heapq.heappush(pq, (new_dist, u))

  return D

n = 10
edges = [[0, 1, 15],
         [1, 2, 21],
         [0, 3, 12],
         [3, 4, 4],
         [3, 5, 10],
         [4, 5, 3],
         [5, 6, 10],
         [1, 6, 7],
         [2, 7, 25],
         [6, 7, 19],
         [4, 8, 13],
         [8, 9, 15],
         [6, 9, 9],
         [7, 9, 5]]

graph = [[] for _ in range(n)]

for u, v, w in edges:
  graph[u].append((v, w))
  graph[v].append((u, w))

start = timeit.default_timer()
dist = [AllPairsShortest((n, graph), start_node) for start_node in range(n)]
end = timeit.default_timer()

for i in range(n):
  for j in range(n - 1):
    if i != j:
      if i > j:
        dist[i][j] = ''

for d in dist:
  print(d)

print(f"Execution Time : {end - start:.10f} sec")