import sys
from collections import deque


n, q = int(input()), deque()

for _ in range(n):
  commands = sys.stdin.readline().split()

  if len(commands) == 1:
    command = commands[0]

    if command == "pop":
      if q:
        print(q.popleft())
      else:
        print(-1)
    elif command == "size":
      print(len(q))
    elif command == "empty":
      if q:
        print(0)
      else:
        print(1)
    elif command == "front":
      if q:
        print(q[0])
      else:
        print(-1)
    elif command == "back":
      if q:
        print(q[-1])
      else:
        print(-1)
  else:
    q.append(int(commands[1]))