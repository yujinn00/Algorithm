import sys

n, k = map(int, sys.stdin.readline().split())
money, count = list(), 0

for _ in range(n):
  money.append(int(sys.stdin.readline()))

for i in money[::-1]:
  if k >= i:
    count += k // i
    k %= i

    if k == 0:
      break

print(count)