#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, result;
int a, b, c;
vector<pair<int, pair<int, int>>> v;
int parent[100001];

void init()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
}
int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
void unionParent(int a, int b)
{
    a = parent[a];
    b = parent[b];
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

void solution()
{
    int max_cost = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int cost = v[i].first;
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;

        if (findParent(n1) != findParent(n2))
        {
            if (max_cost < cost)
                max_cost = cost;
            unionParent(n1, n2);
            result += cost;
        }
    }
    result -= max_cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    solution();
    printf("%d\n", result);
}