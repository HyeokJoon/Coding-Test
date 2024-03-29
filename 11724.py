import sys
def input(): return sys.stdin.readline().rstrip()


n, m = map(int, input().split())

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


for _ in range(m):
    v1, v2 = map(int, input().split())
    unionParent(v1, v2)

parentList = []
for i in range(1, n+1):
    parentList.append(findParent(i))

result = set(parentList)
print(len(result))
