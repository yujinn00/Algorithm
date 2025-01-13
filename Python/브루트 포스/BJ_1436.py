import sys

n = int(sys.stdin.readline())
count, num = 1, 666

while n != count:
  num += 1

  if "666" in str(num):
    count += 1

print(num)