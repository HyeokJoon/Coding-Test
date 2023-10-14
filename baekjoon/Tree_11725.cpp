#include <iostream>
#include <queue>
using namespace std;

int N;
int visited[100001];
int parent[100001];
queue<int> q[100001];
void init()
{
    cin >> N;
    int n1, n2;
    for (int i = 1; i < N; i++)
    {
        cin >> n1 >> n2;
        if (n1 == 1)
        {
            parent[n2] = 1;
            visited[1] = 1;
            q[1].push(n2);
        }
        else if (n2 == 1)
        {
            parent[n1] = 1;
            visited[1] = 1;
            q[1].push(n1);
        }
        else
        {
            q[n1].push(n2);
            q[n2].push(n1);
        }
    }
}

void solution()
{
    int cur;
    queue<int> nodes;
    nodes.push(1);
    while (!nodes.empty())
    {
        cur = nodes.front();
        nodes.pop();
        while (!q[cur].empty())
        {
            int child = q[cur].front();
            q[cur].pop();
            if (visited[child] == 0)
            {
                visited[child] = 1;
                parent[child] = cur;
                nodes.push(child);
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parent[i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
}