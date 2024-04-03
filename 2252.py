from collections import deque
from collections import defaultdict


def dfs(i):
    global answer
    for v in vertex[i]:
        if visited[v]:
            continue
        visited[v] = 1
        dfs(v)

    answer += [i]
    return


def init(m):
    for _ in range(m):
        v1, v2 = map(int, input().split())
        vertex[v1].append(v2)


def solution(n, answer):
    for i in range(1, n+1):
        if visited[i]:
            continue
        visited[i] = 1
        dfs(i)

    for i in range(len(answer)):
        print(answer[-1-i], end=" ")


n, m = map(int, input().split())
vertex = [[] for _ in range(n+1)]
visited = [0] * (n+1)
answer = []

init(m)
solution(n, answer)
