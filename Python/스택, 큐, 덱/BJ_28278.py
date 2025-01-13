import sys

n, s = int(input()), []

for i in range(n):
  commands = sys.stdin.readline().split()
  
  if len(commands) == 1:
    command = int(commands[0])

    if command == 2:
      if s:
        print(s.pop())
      else:
        print(-1)
    if command == 3:
      print(len(s))
    if command == 4:
      if not s:
        print(1)
      else:
        print(0)
    if command == 5:
      if s:
        print(s[-1])
      else:
        print(-1)
  else:
    s.append(int(commands[-1]))