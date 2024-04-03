from collections import deque
import sys
def input(): return sys.stdin.readline().rstrip()


def makeMap():
    global startx, starty, r, c, _map, deq, visited
    for i in range(r):
        line = input()
        for j in range(c):
            _map[i][j] = line[j]
            if _map[i][j] == 'S':
                deq.append((i, j))
                visited[i][j] = 1
                startx, starty = i, j
            elif _map[i][j] == '*':
                waterlist.append((i, j))


def BFS():
    global r, c, _map, deq, visited
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    l = len(deq)
    for _ in range(l):
        x, y = deq.popleft()
        if _map[x][y] == '*':
            continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= r or ny >= c:
                continue
            if visited[nx][ny] or _map[nx][ny] == 'X' or _map[nx][ny] == '*':
                continue
            if _map[nx][ny] == 'D':
                return visited[x][y] + 1
            deq.append((nx, ny))
            visited[nx][ny] = visited[x][y] + 1
    return 0


def watering(r, c, _map, waterlist):
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    l = len(waterlist)
    for _ in range(l):
        x, y = waterlist.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= r or ny >= c:
                continue
            if _map[nx][ny] == '.':
                _map[nx][ny] = '*'
                waterlist.append((nx, ny))


r, c = map(int, input().split())
_map = [[0]*c for _ in range(r)]
visited = [[0]*c for _ in range(r)]
startx, starty = 0, 0
deq = deque()
waterlist = deque()
flag = True
cnt = 0

makeMap()
while flag:
    result = BFS()
    watering(r, c, _map, waterlist)
    if result != 0 or len(deq) == 0:
        flag = False
if result != 0:
    print(result-1)
else:
    print('KAKTUS')
# print(_map)
