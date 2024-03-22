#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int map[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, L, R;
int sum, cnt;
vector<pair<int, int>> v;

void dfs(int x, int y, vector<pair<int, int>> &v)
{
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= N || ny >= N || nx < 0 || ny < 0 || visited[nx][ny])
            continue;
        if (abs(map[x][y] - map[nx][ny]) < L || abs(map[x][y] - map[nx][ny]) > R)
            continue;
        visited[nx][ny] = 1;
        v.push_back({nx, ny});
        sum += map[nx][ny];
        dfs(nx, ny, v);
    }
}
int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    while (true)
    {
        bool flag = 0;
        memset(visited, 0, sizeof(visited));
        // fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = map[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1)
                        continue;
                    for (pair<int, int> b : v)
                    {
                        map[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }
    cout << cnt << "\n";
}
