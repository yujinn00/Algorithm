import sys

n, m = map(int, sys.stdin.readline().split())
board, result = [], []

for _ in range(n):
  board.append(sys.stdin.readline())

for a in range(n - 7):
  for b in range(m - 7):
    white, black = 0, 0

    for i in range(a, a + 8):
      for j in range(b, b + 8):
        if (i + j) % 2 == 0: # 짝수는 첫 번째 색과 같음
          if board[i][j] != 'W':
            white += 1
          else:
            black += 1
        else: # 홀수는 첫 번째 색과 다름
          if board[i][j] != 'W':
            black += 1
          else:
            white += 1

    result.append(white) # 둘 중에 낮은 수를
    result.append(black) # 출력하면 그게 답

print(min(result))