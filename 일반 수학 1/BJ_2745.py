n, b = input().split()
arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

n = n[::-1]
res = 0

for i, val in enumerate(n):
    res += int(b) ** i * arr.index(val)

print(res)