t = int(input())

for n in range(t):
  c = int(input())

  quarter = c // 25
  c %= 25
  dime = c // 10
  c %= 10
  nickel = c // 5
  c %= 5
  penny = c // 1

  print(quarter, dime, nickel, penny)