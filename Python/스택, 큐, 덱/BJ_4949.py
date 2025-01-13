import sys

while True:
  sentence, s = sys.stdin.readline().rstrip(), []

  if sentence == '.':
    break
  for i in sentence:
    if i == '(' or i == '[':
      s.append(i)
    elif i == ')':
      if not s or s[-1] != '(':
        print("no")
        break
      s.pop()
    elif i == ']':
      if not s or s[-1] != '[':
        print("no")
        break
      s.pop()
  else:
    if s:
      print("no")
    else:
      print("yes")