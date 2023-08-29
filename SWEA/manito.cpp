#include <iostream>
#include <queue>
#include <stdio.h>
#include <climits>
#include <stack>

using namespace std;

class Edge
{
public:
    int v1, v2;
    int cost;
    bool operator<(const Edge others) const
    {
        return this->cost > others.cost;
    }
};
int visited[160000];
Edge edges[160000];
priority_queue<Edge> pq[160000];
stack<Edge> loot[160000];

int T, N, M;
int R, total;
int minCost;
int cost[402] = {0};
// int cost[402][402] = {0};

void init()
{
    int num1, num2, c;
    scanf("%d %d", &N, &M);
    // cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &num1, &num2, &c);
        // cin >> num1 >> num2 >> c;
        edges[i].v1 = num1;
        edges[i].v2 = num2;
        edges[i].cost = c;

        pq[num1].push(edges[i]);
    }
}
int start, dest;
bool dfs(int r)
{
    visited[start] = 1;
    while (!pq[r].empty())
    {
        Edge curEdge = pq[r].top();
        start = curEdge.v1;
        dest = curEdge.v2;
        loot->push(curEdge);
        pq[r].pop();

        if (visited[dest] == 0)
        {
            dfs(dest);
        }
        else
        {
            return true;
        }
    }
    return false;
}

void clear()
{
    for (int i = 1; i <= N; i++)
    {
        cost[i] = 0;
    }
}

int main()
{
    // freopen("SWEA/input.txt", "r", stdin);
    scanf("%d", &T);
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        minCost = INT_MAX;
        init();
        for (int i = 1; i <= N; i++)
        {
            if (dfs(i))
            {
                while (!loot->empty())
                {
                    Edge edge = loot->top();
                    loot->pop();
                    cost[i] += edge.cost;
                }
                if (minCost > cost[i])
                {
                    minCost = cost[i];
                }
            }
        }
        if (minCost == INT_MAX)
        {
            minCost = -1;
        }
        printf("#%d %d\n", i, minCost);
        // clear();
    }
    return 0;
}
/*
1
4 1
1 2 3

답 : -1

2
4 5
1 2 2
2 1 8
1 3 1
3 1 4
2 2 2

5 6
1 2 2
2 3 1
3 4 1
4 5 1
5 1 1
1 1 3

답 : 2
답 : 6

1
4 5
1 2 2
2 1 5000
1 3 10000
3 1 4
2 2 10000

답 : 2

*/