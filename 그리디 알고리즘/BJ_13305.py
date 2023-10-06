import sys

n = int(sys.stdin.readline())
lengths = list(map(int, sys.stdin.readline().split()))
prices = list(map(int, sys.stdin.readline().split()))

minPrice, minCost = prices[0], 0

for i in range(n - 1):
  if minPrice > prices[i]:
    minPrice = prices[i]
  minCost += minPrice * lengths[i]

print(minCost)