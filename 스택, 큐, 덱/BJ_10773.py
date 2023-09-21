import sys

k, s, sum = int(input()), [], 0

for _ in range(k):
  money = int(sys.stdin.readline())

  if money != 0:
    s.append(money)
  else:
    s.pop()

for i in range(len(s)):
  sum += s[i]

print(sum)