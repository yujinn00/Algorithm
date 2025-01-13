from collections import deque

q = deque(range(1, int(input()) + 1))

while len(q) > 1:
  q.popleft()
  q.append(q.popleft()) # rotate(-1) : O(N) => 느림

print(q[0])