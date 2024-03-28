import heapq
n = int(input())

max_heap = []
min_heap = []

for _ in range(n):
    s, e = map(int, input().split())
    if s > e:
        heapq.heappush(max_heap, -s)
        heapq.heappush(min_heap, e)
    else:
        heapq.heappush(max_heap, -e)
        heapq.heappush(min_heap, s)

d = int(input())

cur_s = heapq.heappop(min_heap)
cur_e = -heapq.heappop(max_heap)

ret = n


def check(ei, si):
    if d >= ei - si:
        return True
    else:
        return False


tmps = 1
tmpe = 1
while 1:
    if check(cur_e, cur_s):
        break
    else:
        if not min_heap or not max_heap or ret == 0:
            ret = 0
            break
        ns = heapq.heappop(min_heap)
        ne = -heapq.heappop(max_heap)

        if ns - cur_s < cur_e - ne:
            heapq.heappush(min_heap, ns)
            if cur_e == ne:
                tmpe += 1
            else:
                ret -= tmpe
            cur_e = ne
        else:
            heapq.heappush(max_heap, -ne)
            if cur_s == ns:
                tmps += 1
            else:
                ret -= tmps
            cur_s = ns

print(ret)
