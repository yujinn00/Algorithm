import sys
import heapq
import collections

# 프림 알고리즘
def prim_mst(graph, start_node):
  visited[start_node] = 1  # 방문 갱신
  candidate = graph[start_node]  # 인접 간선 추출
  heapq.heapify(candidate)  # 우선순위 큐 생성
  mst = []  # mst

  while candidate:
    weight, u, v = heapq.heappop(candidate)  # 가중치가 가장 적은 간선 추출
    if visited[v] == 0:  # 방문하지 않았다면
      visited[v] = 1  # 방문 갱신
      mst.append((u, v, weight))  # mst에 간선 정보 추가

      for edge in graph[v]:  # 다음 인접 간선 탐색
        if visited[edge[2]] == 0:  # 방문한 노드가 아니라면 (순환 방지)
          heapq.heappush(candidate, edge)  # 우선순위 큐에 간선 삽입

  return mst

n, m = map(int, sys.stdin.readline().split())  # 노드 수, 간선 수
graph = collections.defaultdict(list)  # 빈 그래프 생성
visited = [0] * (n + 1)  # 노드의 방문 정보 초기화

# 무방향 그래프 생성
for i in range(m):  # 간선 정보 입력 받기
  u, v, weight = map(int, input().split())
  graph[u].append([weight, u, v])
  graph[v].append([weight, v, u])

minimum_spanning_tree = prim_mst(graph, 2)  # 시작 노드가 2인 경우

for edge in minimum_spanning_tree:
  print(edge[0], edge[1], edge[2])

# 프림 알고리즘은 시작 노드로부터
# 가장 가까운 노드를 선택하는 방식으로 동작합니다.
# 그래프의 노드 개수가 많을 때 효율적입니다.

# https://8iggy.tistory.com/159