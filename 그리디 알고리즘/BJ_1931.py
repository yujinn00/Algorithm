import sys

meetings, time, count = [], 0, 0

for _ in range(int(sys.stdin.readline())):
  start, end = map(int, sys.stdin.readline().split())
  meetings.append((start, end))

meetings.sort(key=lambda x : (x[1], x[0]))

for meeting in meetings:
  if time <= meeting[0]:
    time = meeting[1]
    count += 1

print(count)