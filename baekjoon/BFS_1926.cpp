#include <iostream>
#include <queue>

using namespace std;
int n, m, result, _max;
int map[505][505];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int visited[505][505];
queue<pair<int, int>> q;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solution(int x, int y)
{
    if (map[x][y] == 0)
    {
        visited[x][y] = 1;
        return;
    }
    result++;
    q.push(make_pair(x, y));
    int cnt = 0;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        if (visited[cur_x][cur_y])
        {
            q.pop();
            continue;
        }
        visited[cur_x][cur_y] = 1;
        q.pop();
        int cur = map[cur_x][cur_y];
        if (cur == 1)
        {
            cnt++;
            for (int i = 0; i < 4; i++)
            {
                if (!visited[cur_x + dx[i]][cur_y + dy[i]])
                {
                    q.push(make_pair(cur_x + dx[i], cur_y + dy[i]));
                }
            }
        }
    }
    if (cnt > _max)
        _max = cnt;
}

int main()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j])
                solution(i, j);
        }
    }
    printf("%d\n%d\n", result, _max);
}