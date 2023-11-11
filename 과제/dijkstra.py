import heapq

def ShortestPath(G, s):
  n, edges = G

  # 최단거리 배열 초기화
  D = [float('inf')] * n
  D[s] = 0  # 시작 노드의 최단거리는 0

  # 우선순위 큐를 사용한 다익스트라 알고리즘
  pq = [(0, s)]  # (거리, 노드)의 튜플을 저장하는 우선순위 큐
  while pq:
    dist_u, u = heapq.heappop(pq)
    if D[u] < dist_u:
      continue  # 이미 처리된 노드는 무시

    # 현재 노드에서 갈 수 있는 모든 인접한 노드들을 확인
    for v, weight in edges[u]:
      new_dist = D[u] + weight
      if new_dist < D[v]:
        D[v] = new_dist
        heapq.heappush(pq, (new_dist, v))

  return D

# 입력 데이터
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

# 그래프 생성
graph = [[] for _ in range(n)]
for u, v, w in edges:
  graph[u].append((v, w))
  graph[v].append((u, w))

# 각 노드에서 모든 노드까지의 최단 거리 계산
all_shortest_distances = [ShortestPath((n, graph), start_node) for start_node in range(n)]

# 결과 출력
for i, distances in enumerate(all_shortest_distances):
  print(distances)