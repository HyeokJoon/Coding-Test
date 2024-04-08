import sys
def input(): return sys.stdin.readline().rstrip()


t = int(input())


def solution():
    n = int(input())
    arr = []
    for _ in range(n):
        score1, score2 = map(int, input().split())
        arr.append((score1, score2))

    arr.sort()
    cnt = 1
    s2 = arr[0][1]
    for i in range(1, n):
        if arr[i][1] < s2:
            cnt += 1
            s2 = arr[i][1]

    print(cnt)


for _ in range(t):
    solution()
