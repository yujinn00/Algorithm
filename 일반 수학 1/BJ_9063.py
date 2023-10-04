import sys

n, xList, yList = int(sys.stdin.readline()), [], []

for _ in range(n):
  x, y = map(int, sys.stdin.readline().split())

  xList.append(x)
  yList.append(y)

print((max(xList) - min(xList)) * (max(yList) - min(yList)))