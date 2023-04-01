#include <iostream>
#include <queue>
#define MAX_N 100001
#define MAX_M 200001
using namespace std;

class Edge
{
public:
    int v1, v2;
    int dest;
    bool operator<(const Edge others) const
    {
        return this->dest > others.dest;
    }
};

int visited[MAX_N];
Edge edges[MAX_M];
priority_queue<Edge> pq[MAX_N];
int order[MAX_N];
int N, M, R, cnt;

void init()
{
    cnt = 0;
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 1; i <= N; i++)
    {
        order[i] = 0;
    }
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        edges[i].v1 = u;
        edges[i].v2 = v;
        edges[i].dest = v;
        pq[u].push(edges[i]);
        edges[i].dest = u;
        pq[v].push(edges[i]);
    }
}

void dfs(int r)
{
    order[r] = ++cnt;
    visited[r] = 1;
    int v1, v2;
    while (!pq[r].empty())
    {
        Edge curEdge = pq[r].top();
        pq[r].pop();
        int dest = curEdge.dest;
        if (visited[dest] == 0)
        {
            dfs(dest);
        }
    }
}

void printResult()
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", order[i]);
    }
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    init();
    dfs(R);
    printResult();
}
