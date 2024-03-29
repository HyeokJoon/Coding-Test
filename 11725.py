import sys
def input(): return sys.stdin.readline().rstrip()


n = int(input())

vector = [[] for _ in range(n+1)]
queue = []
visited = [0]*(n+1)
visited[1] = 0
ret = [0]*(n+1)


def bfs(x):
    queue.append((x, 0))
    while queue:
        top = queue.pop(0)
        cur = top[0]
        parent = top[1]
        ret[cur] = parent
        for vertex in vector[cur]:
            if visited[vertex]:
                continue
            visited[vertex] = 1
            queue.append((vertex, cur))


for _ in range(1, n):
    v1, v2 = map(int, input().split())
    vector[v1].append(v2)
    vector[v2].append(v1)

bfs(1)
for i in range(2, n+1):
    print(ret[i])
