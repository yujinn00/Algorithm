import sys

a, b = map(int, sys.stdin.readline().split())

A = set(sys.stdin.readline().split())
B = set(sys.stdin.readline().split())

print(len((A | B) - (A & B)))