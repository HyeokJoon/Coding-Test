import heapq
import sys
def input(): return sys.stdin.readline().rstrip()


n = int(input())
m = int(input())

vertex = [[] for _ in range(n+1)]
for _ in range(m):
    v1, v2, cost = map(int, input().split())
    vertex[v1].append([v2, cost])

s, e = map(int, input().split())
visited = [0]*(n+1)
INF = 10e9
Dist = [int(INF) for _ in range(n+1)]


def bfs(start, end):
    queue = []
    visited[start] = 1
    Dist[start] = 0
    heapq.heappush(queue, [0, start])

    while queue:
        cost, cur = heapq.heappop(queue)
        if Dist[cur] < cost:
            continue
        for next, ncost in vertex[cur]:
            if Dist[next] > cost + ncost:
                Dist[next] = cost + ncost
                heapq.heappush(queue, (Dist[next], next))

    print(Dist[end])


bfs(s, e)
