#include <iostream>
#include <queue>
using namespace std;
int N, K;
int visited[100001];
int cnt[100001];
queue<int> q;

void init()
{
    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
}

void solution()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == K)
            break;
        if (x - 1 >= 0 && visited[x - 1] == 0)
        {
            visited[x - 1] = 1;
            q.push(x - 1);
            cnt[x - 1] = cnt[x] + 1;
        }
        if (x + 1 <= 100000 && visited[x + 1] == 0)
        {
            visited[x + 1] = 1;
            q.push(x + 1);
            cnt[x + 1] = cnt[x] + 1;
        }
        if (2 * x <= 100000 && visited[2 * x] == 0)
        {
            visited[2 * x] = 1;
            q.push(2 * x);
            cnt[2 * x] = cnt[x] + 1;
        }
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", cnt[K]);
}