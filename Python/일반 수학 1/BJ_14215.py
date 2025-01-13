stick = sorted(list(map(int, input().split())))

if stick[2] >= stick[0] + stick[1]:
  print((stick[0] + stick[1]) * 2 - 1)
else:
  print(sum(stick))