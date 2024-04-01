import heapq
import sys
def input(): return sys.stdin.readline().rstrip()


n, m, k, x = map(int, input().split())
INF = int(10e9)
vertex = [[] for _ in range(n+1)]
Dist = [INF]*(n+1)

for _ in range(m):
    a, b = map(int, input().split())
    vertex[a].append((b, 1))

# print(vertex)


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start))
    Dist[start] = 0
    ret = 0

    while queue:
        cost, cur = heapq.heappop(queue)

        for i in vertex[cur]:
            next = i[0]
            ncost = i[1]

            if Dist[next] > cost + ncost:
                Dist[next] = cost + ncost
                heapq.heappush(queue, (Dist[next], next))

    for i in range(n+1):
        if Dist[i] == k:
            print(i)
            ret += 1

    if ret == 0:
        print(-1)


dijkstra(x)
