from unittest import result


n = int(input())
map11 = [[0]*n for _ in range(n)]

result_ = 0

global citys
citys = [i+1 for i in range(n)]


def add(arr):
    sum = 0
    for i in range(0, len(arr)-1):
        sum = sum+map11[arr[i]][arr[i+1]]
    return sum


def dfs(idx, arr):
    global result_
    if idx == n:
        tmp = add(arr)
        if (result_ < tmp):
            result_ = tmp
        return
    for i in range(idx, len(citys)):
        arr[idx] = citys[i]
        dfs(idx+1, arr)
        del arr[idx]


for i in range(n):
    map11[i] = list(map(int, input().split()))

print(map11)
arr = [0]*n
dfs(0, arr)

print(result_)

N = int(input())
arr = [None] * (2 * 1000000)
for _ in range(N):
    value = int(input()) + 1000000
    arr[value] = 1
for i in range(2 * 1000000):
    if arr[i] == 1:
        print(i - 100000)
