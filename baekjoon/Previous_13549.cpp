#include <iostream>
#include <queue>
using namespace std;

int N, K, cnt;
int visited[100001];
int map[100001];
queue<int> q;

void init()
{
    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
    for (int i = 0; i < 100001; i++)
    {
        map[i] = 1000000;
    }
    map[N] = 0;
}

void BFS()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x - 1 >= 0)
        {
            if (map[x - 1] > map[x] + 1)
            {
                map[x - 1] = map[x] + 1;
                q.push(x - 1);
            }
        }
        if (x + 1 <= 100000)
        {
            if (map[x + 1] > map[x] + 1)
            {
                map[x + 1] = map[x] + 1;
                q.push(x + 1);
            }
        }
        if (2 * x <= 100000)
        {
            if (map[2 * x] > map[x])
            {
                q.push(2 * x);
                map[2 * x] = map[x];
            }
        }
    }
}
int main()
{
    init();
    BFS();
    printf("%d\n", map[K]);
}