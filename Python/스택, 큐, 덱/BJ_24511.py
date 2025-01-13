import sys
from collections import deque

n = int(input())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))
m = int(input())
c = list(map(int, sys.stdin.readline().split()))

queueStack = deque()

for i in range(n):
  if a[i] == 0:
    queueStack.append(b[i])

for i in c:
  queueStack.appendleft(i)
  print(queueStack.pop(), end=" ")