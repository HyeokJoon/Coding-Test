n, k = map(int, input().split())
items = [(0, 0)]
arr = [[0] * (k+1) for _ in range(n+1)]

for _ in range(n):
    w, v = map(int, input().split())
    items.append((w, v))

for i in range(1, len(items)):
    w = items[i][0]
    v = items[i][1]
    for weight in range(k+1):
        if weight-w < 0:
            arr[i][weight] = arr[i-1][weight]
        else:
            arr[i][weight] = max(arr[i-1][weight], arr[i-1][weight-w] + v)


print(arr[n][k])
