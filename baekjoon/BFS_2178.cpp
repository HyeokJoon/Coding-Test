#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[102][102];
int visited[102][102];
int dist[102][102];
queue<pair<int, int>> q;
string s;

void init()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            map[i][j + 1] = (int)s[j] - '0';
        }
    }
    dist[1][1] = 1;
    visited[1][1] = 1;
}
void solution()
{
    q.push(make_pair(1, 1));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (!visited[next_x][next_y] && map[next_x][next_y])
            {
                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x, next_y));
                if (!dist[next_x][next_y])
                    dist[next_x][next_y] = dist[x][y] + 1;
                if (next_x == N && next_y == M)
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", dist[N][M]);
}