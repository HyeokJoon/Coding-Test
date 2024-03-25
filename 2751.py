import sys


def input():
    return sys.stdin.readline().rstrip()


arr = [False]*2000002
n = int(input())
for _ in range(n):
    i = int(input())
    arr[i+1000000] = True

for j in range(0, 2000002):
    if arr[j]:
        print(j-1000000)
