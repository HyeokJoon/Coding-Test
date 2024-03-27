import sys
import heapq


def input():
    return sys.stdin.readline().rstrip()


heap = []
answer = []
n = int(input())
for _ in range(n):
    op = int(input())
    if op == 0:
        if len(heap) == 0:
            answer.append(0)
        else:
            answer.append(heapq.heappop(heap))
    else:
        heapq.heappush(heap, int(op)*-1)

for a in answer:
    print(-a)
