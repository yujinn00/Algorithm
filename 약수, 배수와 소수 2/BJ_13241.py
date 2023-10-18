import sys

def GCD(a, b):
  if b == 0:
    return a
  else:
    return GCD(b, a % b)

def LCM(a, b):
  return a * b // GCD(a, b)

a, b = map(int, sys.stdin.readline().split())

print(LCM(a, b))