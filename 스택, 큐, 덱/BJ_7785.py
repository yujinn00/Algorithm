import sys

n, d = int(sys.stdin.readline()), dict()

for _ in range(n):
  person, commute = map(str, sys.stdin.readline().split())

  if commute == "enter":
    d[person] = commute
  else:
    del d[person]

d = sorted(d.keys(), reverse=True)

for i in d:
  print(i)