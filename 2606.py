n = int(input())
e = int(input())

parent = [i for i in range(n+1)]


def findParent(x):
    if parent[x] == x:
        return x
    parent[x] = findParent(parent[x])
    return parent[x]


def unionParent(a, b):
    a = findParent(a)
    b = findParent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


for _ in range(e):
    v1, v2 = map(int, input().split())
    unionParent(v1, v2)

cnt = 0
for i in range(1, n+1):
    if findParent(i) == findParent(1):
        cnt += 1

print(cnt-1)
