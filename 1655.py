import sys
import heapq


def input():
    return sys.stdin.readline().rstrip()


max_heap = []
min_heap = []
answer = []

n = int(input())
mid = int(input())
answer.append(mid)
for _ in range(n-1):
    num = int(input())
    if mid > num:
        heapq.heappush(max_heap, -num)
    else:
        heapq.heappush(min_heap, num)
    left = len(max_heap)
    right = len(min_heap)
    if right > (left+1):
        heapq.heappush(max_heap, -mid)
        mid = heapq.heappop(min_heap)
    elif right < left:
        heapq.heappush(min_heap, mid)
        mid = -heapq.heappop(max_heap)
    answer.append(mid)

for a in answer:
    print(a)
