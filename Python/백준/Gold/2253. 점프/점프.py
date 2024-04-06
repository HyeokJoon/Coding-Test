n, m = map(int, input().split())
INF = 10001
_map = [[INF] * (int((2*n)**0.5)+2) for _ in range(n+1)]
isvalid = [True] * (n+1)

for _ in range(m):
    small = int(input())
    isvalid[small] = False

_map[1][0] = 0

for r in range(2, n+1):
    if not isvalid[r]:
        continue
    for j in range(1, int((2*n)**0.5)+1):
        _map[r][j] = min(_map[r-j][j-1], _map[r-j][j], _map[r-j][j+1]) + 1

ret = min(_map[n])
if ret == INF:
    print(-1)
else:
    print(ret)
