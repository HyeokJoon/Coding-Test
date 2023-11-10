#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[9][9];
int visited[9][9];
int value[9][9][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                q.push({i, j});
        }
    }
}
void solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
                }
    }
}

int main()
{
    init();
}