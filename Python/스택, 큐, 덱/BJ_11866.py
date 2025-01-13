# 인덱스 계산 : 상대적 빠름
n, k = map(int, input().split())
l, i, res = list(range(1, n + 1)), 0, []

while l:
  i += k - 1
  i %= len(l)
  res.append(str(l.pop(i)))

print("<" + ", ".join(res) + ">")

# # rotate() 메소드 활용 : 상대적 느림
# from collections import deque

# n, k = map(int, input().split())
# q, res = deque(range(1, n + 1)), []

# while q:
#   q.rotate(1 - k)
#   res.append(str(q.popleft()))

# print("<" + ", ".join(res) + ">")