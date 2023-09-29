import sys

n = int(sys.stdin.readline())
p = list(map(int, sys.stdin.readline().split()))

p.sort()

time, sum = 0, 0

for i in p:
  time += i
  sum += time

print(sum)