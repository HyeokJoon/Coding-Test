#include <iostream>
#include <vector>
using namespace std;

int N, maxi;
int map[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> v;

void shape1(int x, int y, int s)
{
    int tmp_sum = 0;
    // ----모양
    if (s == 0)
        tmp_sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3];
    // 세로 모양
    if (s == 1)
        tmp_sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y];
}

void shape2(int x, int y, int s)
{
    int tmp_sum = 0;
    if (s == 0) // ㅏ 모양
        tmp_sum = map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1];
    if (s == 1) // ㅓ 모양
        tmp_sum = map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x + 1][y + 1];
    
}

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

bool isValid()
{
    int gapx = v[0].first;
    int gapy = v[0].second;
    return true;
}

void dfs(int x, int y)
{
    if (v.size() == 4)
    {
        // logic
        if (isValid())
        {
            int sum = 0;
            for (int i = 0; i < 4; i++)
            {
                sum += map[v[i].first][v[i].second];
                // cout << v[i].first << "," << v[i].second << ' ';
            }
            maxi = max(maxi, sum);
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny])
            continue;
        visited[nx][ny] = 1;
        v.push_back({nx, ny});
        dfs(nx, ny);
        v.pop_back();
        visited[nx][ny] = 0;
    }
}

int main()
{
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;
        init();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = 1;
                v.push_back({i, j});
                dfs(i, j);
                v.pop_back();
                visited[i][j] = 1;
            }
        }
        cout << maxi;
    }
}