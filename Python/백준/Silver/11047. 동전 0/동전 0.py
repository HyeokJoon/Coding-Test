n, k = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

ret = 0
for i in range(n-1, -1, -1):
    ret += k//arr[i]
    k %= arr[i]

print(ret)
