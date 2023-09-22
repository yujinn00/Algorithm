n, s, target = int(input()), [], 1

students = list(map(int, input().split()))

for student in students:
  if student != target:
    s.append(student)
  else:
    target += 1

    while s:
      if s[-1] == target:
        target += 1
        s.pop()
      else:
        break

if not s:
    print("Nice")
else:
  tmp = s[0]

  for i in s[1:]:
    if tmp < i:
      print("Sad")
      break
  else:
    print("Nice")