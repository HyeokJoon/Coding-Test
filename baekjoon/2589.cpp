#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n, m;
int map[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int mx;

//어느 한 지점에서 부터 시작하는 bfs
void bfs(int y, int x)
{
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (visited[ny][nx])
                continue;
            if (map[ny][nx] == 'W')
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
}

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

int main()
{
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'L')
                bfs(i, j);
        }
    }
    cout << mx - 1 << "\n";
}