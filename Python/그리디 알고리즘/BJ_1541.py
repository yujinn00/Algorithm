import sys

calc = sys.stdin.readline().split('-')
res = 0

for i in calc[0].split('+'):
  res += int(i)

for i in calc[1:]:
  for j in i.split('+'):
    res -= int(j)

print(res)