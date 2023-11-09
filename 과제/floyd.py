def AllPairsShortest(D, n):
  for k in range(n):
    for i in range(n):
      if i != k:
        for j in range(n):
          if j != k and j != i:
            D[i][j] = min(D[i][k] + D[k][j], D[i][j])

  for i in range(n):
    for j in range(n - 1):
      if i != j:
        if i > j:
          D[i][j] = ''

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

INF = float("inf")
dist = [[INF] * n for _ in range(n)]

for i in range(n):
  dist[i][i] = 0

for u, v, w in edges:
  dist[u][v] = w
  dist[v][u] = w

AllPairsShortest(dist, n)

for d in dist:
  print(d)