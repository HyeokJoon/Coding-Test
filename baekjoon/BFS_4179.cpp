#include <iostream>
#include <queue>
using namespace std;
int R, C;
int visited[1002][1002];
int visitedP[1002][1002];
int cnt[1002][1002];
int cntP[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;
queue<pair<int, int>> qf;

string s;

void init()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '#')
            {
                visited[i][j + 1] = 1;
                visitedP[i][j + 1] = 1;
            }
            if (s[j] == 'F')
            {
                visited[i][j + 1] = 1;
                visitedP[i][j + 1] = 1;
                qf.push(make_pair(i, j + 1));
            }
            else if (s[j] == 'J')
            {
                cntP[i][j + 1] = 1;
                q.push(make_pair(i, j + 1));
            }
        }
    }
}

void fire_move()
{
    while (!qf.empty())
    {
        int x = qf.front().first;
        int y = qf.front().second;
        qf.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] > 0 && x + dx[i] <= R && y + dy[i] > 0 && y + dy[i] <= C)
            {
                if (visited[x + dx[i]][y + dy[i]] == 0) // 방문하지 않았으면
                {
                    visited[x + dx[i]][y + dy[i]] = 1;
                    qf.push(make_pair(x + dx[i], y + dy[i]));
                    cnt[x + dx[i]][y + dy[i]] = cnt[x][y] + 1;
                }
            }
        }
    }
}
int solution()
{
    fire_move();
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == 1 || y == 1 || x == R || y == C)
        {
            return cntP[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (visitedP[x + dx[i]][y + dy[i]] == 0 && (cnt[x + dx[i]][y + dy[i]] >= cntP[x][y] + 1 || cnt[x + dx[i]][y + dy[i]] == 0))
            {
                q.push(make_pair(x + dx[i], y + dy[i]));
                cntP[x + dx[i]][y + dy[i]] = cntP[x][y] + 1;
                visitedP[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    init();
    int result = solution();
    if (result == -1)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    printf("%d\n", result);
}