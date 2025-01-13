import sys

t = int(input())

for _ in range(t):
  vps, s = sys.stdin.readline().strip(), []

  for i in vps:
    if i == '(':
      s.append(i)
    elif i == ')':
      if s:
        s.pop()
      else:
        print("NO")
        break
  else:
    if s:
      print("NO")
    else:
      print("YES")