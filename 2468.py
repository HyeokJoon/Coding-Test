import sys
sys.setrecursionlimit(10 ** 6)

n = int(input())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
_map = [[0]*n for _ in range(n)]
visited = [[0]*n for _ in range(n)]
ret = 0

for i in range(n):
    _map[i] = list(map(int, input().split()))

maxi = max(map(max, _map))


def dfs(water, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if visited[nx][ny] or _map[nx][ny] <= water:
            continue
        visited[nx][ny] = 1
        dfs(water, nx, ny)


for water in range(0, maxi):
    visited = [[0]*n for _ in range(n)]
    cnt = 0

    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0 and _map[i][j] > water:
                visited[i][j] = 1
                dfs(water, i, j)
                cnt += 1

    ret = max(cnt, ret)


print(ret)
