import sys
def input(): return sys.stdin.readline().rstrip()


v, e = map(int, input().split())


edges = []
parent = [i for i in range(v+1)]
for _ in range(e):
    v1, v2, cost = map(int, input().split())
    edges.append((cost, v1, v2))
edges.sort(key=lambda x: x[0])
# print(edges)


def findParent(x):
    if parent[x] == x:
        return x
    parent[x] = findParent(parent[x])
    return parent[x]


def unionParent(a, b):
    a = findParent(a)
    b = findParent(b)
    if (a > b):
        parent[a] = b
    else:
        parent[b] = a


def kruskal():
    cnt = 0
    answer = 0
    for cost, v1, v2 in edges:
        # 사이클이면 pass
        if findParent(v1) == findParent(v2):
            continue
        unionParent(v1, v2)
        answer += cost

        cnt += 1
        if cnt == v-1:
            break
    return answer


print(kruskal())
