#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt, total;
int map[1010][1010];
int visitied[1010][1010];
int day[1010][1010];
int day_max;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void init()
{
    cin >> M >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                visitied[i][j] = 1;
                day[i][j] = 0;
                cnt++;
                q.push(make_pair(i, j));
            }
            if (map[i][j] != -1)
                total++;
        }
    }
}

void solution()
{
    if (cnt == total)
        return;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] <= N && y + dy[i] <= M) // 범위 내에 있으면
            {
                if (visitied[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == 0) // 방문가능하면
                {
                    q.push(make_pair(x + dx[i], y + dy[i]));
                    visitied[x + dx[i]][y + dy[i]] = 1;
                    cnt++;
                    day[x + dx[i]][y + dy[i]] = day[x][y] + 1;
                    if (day_max < day[x + dx[i]][y + dy[i]])
                        day_max = day[x + dx[i]][y + dy[i]];
                }
            }
        }
    }
    if (cnt != total)
    {
        day_max = -1;
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", day_max);
}