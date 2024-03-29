import sys
def input(): return sys.stdin.readline().rstrip()


n, m, v = map(int, input().split())

vector = [[] for _ in range(n+1)]

for _ in range(m):
    v1, v2 = map(int, input().split())
    vector[v1].append(v2)
    vector[v2].append(v1)
# print(vector)


for list in vector:
    list.sort()


stack = []
queue = []


def dfs(v):
    print(v, end=' ')
    for vertex in vector[v]:
        if visited[vertex]:
            continue
        else:
            visited[vertex] = 1
            dfs(vertex)


def bfs(v):
    queue.append(v)
    while queue:
        top = queue.pop(0)
        print(top, end=' ')
        for vertex in vector[top]:
            if visited[vertex]:
                continue
            else:
                visited[vertex] = 1
                queue.append(vertex)


visited = [0]*(n+1)
visited[v] = 1
dfs(v)
print()
visited = [0]*(n+1)
visited[v] = 1
bfs(v)
