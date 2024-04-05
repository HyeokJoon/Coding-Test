import sys
def input(): return sys.stdin.readline().rstrip()


def solution():

    n = int(input())
    coinlist = list(map(int, input().split()))
    m = int(input())

    arr = [0] * (m+1)
    arr[0] = 1

    for c in coinlist:
        for i in range(c, m+1):
            arr[i] += arr[i-c]

    print(arr[m])


t = int(input())

for _ in range(t):
    solution()
