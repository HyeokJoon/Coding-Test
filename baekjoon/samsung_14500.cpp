#include <iostream>
#include <queue>
using namespace std;

int N, M, result;
int map[505][505];
int visited[505][505];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

void dfs(int x, int y, int cnt, int sum)
{
    if (cnt == 4)
    {
        if (result < sum)
            result = sum;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > N || ny < 0 || ny > M)
                continue;
            if (visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
                if (cnt == 2)
                    dfs(x, y, cnt + 1, sum + map[nx][ny]);
                visited[nx][ny] = 0;
            }
        }
    }
}

void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                dfs(i, j, 1, map[i][j]);
                visited[i][j] = 0;
            }
        }
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", result);
}