import sys
import heapq
sys.setrecursionlimit(100010)
def input(): return sys.stdin.readline().rstrip()


INF = int(10e9)


n, k = map(int, input().split())
coins = []
dic = [0] * 100001
for _ in range(n):
    c = int(input())
    coins.append(c)
    dic[c] = 1


def need_for_make(k):
    pq = []
    if dic[k]:
        return dic[k]
    if k < 0:
        return INF
    for c in coins:
        heapq.heappush(pq, need_for_make(k-c)+1)
    dic[k] = heapq.heappop(pq)
    return dic[k]


result = need_for_make(k)
if result >= INF:
    print(-1)
else:
    print(result)
