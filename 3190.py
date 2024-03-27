import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())
k = int(input())
now_D = 3  # 현재 방향
now_sec = 0  # 현재 시간
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
posx = 0
posy = 0
flag = 0  # 부딛혔는지 여부

apple = [[0]*n for _ in range(n)]
visited = [[0]*n for _ in range(n)]
direct = []
body = [[0, 0]]

for _ in range(k):
    inputs = list(map(int, input().split()))
    apple[inputs[0]-1][inputs[1]-1] = 1

l = int(input())
for _ in range(l):
    inputs = input().split()
    direct.append(inputs)


def move():
    global posx, posy, now_D, flag
    nx = posx+dx[now_D]
    ny = posy+dy[now_D]
    if nx < 0 or ny < 0 or nx >= n or ny >= n:  # 벽에 부딪혔을 때
        flag = 1
        return
    if visited[nx][ny]:  # 몸에 부딪혔을 때
        flag = 1
        return
    if apple[nx][ny]:   # 사과가 있을 때
        apple[nx][ny] = 0
    else:               # 사과가 없을 때
        tailx = body[0][0]
        taily = body[0][1]
        body.pop(0)
        visited[tailx][taily] = 0
    posx = nx
    posy = ny
    visited[posx][posy] = 1
    body.append([posx, posy])


def changeDirect(D):
    global now_D
    if D == 'L':
        now_D -= 1
        now_D += 4
        now_D %= 4
    else:
        now_D += 1
        now_D %= 4


for d in direct:
    next_sec = int(d[0])
    next_D = d[1]
    while next_sec > now_sec:  # 다음 회전 전까지
        now_sec += 1
        move()
        if flag == 1:
            break
    if flag == 1:
        break
    changeDirect(next_D)
while flag == 0:
    now_sec += 1
    move()

print(now_sec)
