import sys

while True:
  a, b, c = list(map(int, sys.stdin.readline().split()))

  if a == b == c == 0:
    break

  if a + b <= c or b + c <= a or c + a <= b:
    print("Invalid")
  else:
    if a == b == c:
      print("Equilateral")
    elif a == b or b == c or c == a:
      print("Isosceles")
    else:
      print("Scalene")