#include <iostream>
#include <queue>
using namespace std;

int first[6] = {9, 9, 3, 3, 1, 1};
int second[6] = {3, 1, 9, 1, 9, 3};
int third[6] = {1, 3, 1, 9, 3, 9};
int map[65][65][65];
int visited[65][65][65];

int bfs(int count, int x, int y, int z)
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{count, x}, {y, z}});

    while (!q.empty())
    {
        bool flag = 0;
        int count = q.front().first.first;
        int a = q.front().first.second;
        int b = q.front().second.first;
        int c = q.front().second.second;
        visited[a][b][c] = 1;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int na = max(0, a - first[i]);
            int nb = max(0, b - second[i]);
            int nc = max(0, c - third[i]);
            if (visited[na][nb][nc])
                continue;
            if (na > 0 || nb > 0 || nc > 0)
            {
                q.push({{count + 1, na}, {nb, nc}});
                visited[na][nb][nc] = 1;
                continue;
            }
            return count + 1;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int hp[3] = {0, 0, 0};
    for (int i = 0; i < N; i++)
    {
        cin >> hp[i];
    }
    int result = bfs(0, hp[0], hp[1], hp[2]);
    cout << result << "\n";
    // 931
    // 913
    // 391
    // 319
    // 193
    // 139
}
