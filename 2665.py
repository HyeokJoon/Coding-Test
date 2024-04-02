from collections import deque
import sys
def input(): return sys.stdin.readline().rstrip()


dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]


def makeMap(n):
    arr = [[] for _ in range(n+1)]
    for i in range(n):
        arr[i] = input()
    return arr


def bfs(flag, x, y):
    global n
    deq = deque()
    deq.append((x, y, flag))
    visited[x][y] = 1

    while deq:
        curx, cury, curflag = deq.popleft()
        if curflag > visited[curx][cury]:
            continue

        for i in range(4):
            nx = curx + dx[i]
            ny = cury + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue

            if visited[nx][ny]:
                if visited[nx][ny] > curflag and _map[nx][ny] == '1':
                    visited[nx][ny] = curflag
                    deq.append((nx, ny, curflag))
                    continue
                elif visited[nx][ny] > curflag+1 and _map[nx][ny] == '0':
                    visited[nx][ny] = curflag+1
                    deq.append((nx, ny, curflag+1))
                continue

            if _map[nx][ny] == '1':
                visited[nx][ny] = curflag
                deq.append((nx, ny, curflag))
                continue

            elif curflag < 2*n:
                if curflag == 2*n-2:
                    continue
                visited[nx][ny] = curflag+1
                deq.append((nx, ny, curflag+1))


n = int(input())
_map = makeMap(n)
visited = [[0 for _ in range(n+1)] for _ in range(n+1)]
bfs(1, 0, 0)
print(visited[n-1][n-1]-1)
