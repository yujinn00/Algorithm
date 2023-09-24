import sys
from collections import deque

n, q = int(input()), deque(enumerate(map(int, sys.stdin.readline().split()), 1))
res = []

while q:
  index, item = q.popleft()
  res.append(index)
  
  if item > 0:
    q.rotate(-(item - 1))
  else:
    q.rotate(-item)

print(" ".join(map(str, res)))