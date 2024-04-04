
def bfs(i, j):  # 방문하지 않고 인접한 모든 점을 방문하고 방문횟수를 반환
    queue = []
    queue.append((i, j))
    visited[i][j] = 1
    cnt = 1
    while queue:
        x, y = queue.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            if visited[nx][ny] or _map[nx][ny] == '0':
                continue
            queue.append((nx, ny))
            visited[nx][ny] = 1
            cnt += 1
    return cnt


def solution(n, _map, visited, bfs, answer):  # 집이 있고 방문하지 않은 모든 점에서 bfs실행
    for i in range(n):
        for j in range(n):
            if _map[i][j] == '0' or visited[i][j]:
                continue
            cnt = bfs(i, j)
            answer.append(cnt)


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


n = int(input())

_map = [0]*n
visited = [[0]*n for _ in range(n)]

for i in range(n):  # 지도 만들기
    _map[i] = input()

answer = []
solution(n, _map, visited, bfs, answer)
answer.sort()

print(len(answer))
for i in answer:
    print(i)
