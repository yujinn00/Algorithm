import sys
from collections import deque

n, q = int(input()), deque()

for _ in range(n):
  commands = sys.stdin.readline().split()
  command = int(commands[0])

  if len(commands) == 1:
    if command == 3:
      if q:
        print(q.popleft())
      else:
        print(-1)
    if command == 4:
      if q:
        print(q.pop())
      else:
        print(-1)
    if command == 5:
      print(len(q))
    if command == 6:
      if q:
        print(0)
      else:
        print(1)
    if command == 7:
      if q:
        print(q[0])
      else:
        print(-1)
    if command == 8:
      if q:
        print(q[-1])
      else:
        print(-1)
  else:
    if command == 1:
      q.appendleft(int(commands[1]))
    if command == 2:
      q.append(int(commands[1]))