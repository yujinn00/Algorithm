s, substring = input(), set()

for start in range(len(s)):
  for end in range(start + 1, len(s) + 1):
    substring.add(s[start:end])

print(len(substring))