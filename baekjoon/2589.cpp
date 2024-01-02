#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
pair<int, int> startPoint;
pair<int, int> endPoint;
queue<pair<int, int>> q;
int maxLen;

void init()
{
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j];
        }
    }
}
void solution()
{
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny] || map[nx][ny] == 'W')
                continue;
            visited[nx][ny] = visited[cur_x][cur_y] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            q.push({i, j});
            solution();
        }
    }
}