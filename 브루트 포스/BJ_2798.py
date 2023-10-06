import sys

n, m = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))
result = 0

for i in range(n - 2):
  if m < cards[i]:
    continue
  for j in range(i + 1, n - 1):
    if m < cards[i] + cards[j]:
      continue
    for k in range(j + 1, n):
      sum = cards[i] + cards[j] + cards[k]
      if result < sum and sum <= m:
        result = sum

print(result)