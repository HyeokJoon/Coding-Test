n, m = map(int, input().split())
maze = [0] * n
visited = [[0]*m for _ in range(n)]
for i in range(n):
    maze[i] = input()

# print(maze)
# print(maze[0][0])
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
queue = []
visited[0][0] = 1
queue.append((0, 0))


def bfs():
    while queue:
        x, y = queue.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if visited[nx][ny] or maze[nx][ny] == '0':
                continue
            visited[nx][ny] = visited[x][y] + 1
            queue.append((nx, ny))


bfs()
print(visited[n-1][m-1])
