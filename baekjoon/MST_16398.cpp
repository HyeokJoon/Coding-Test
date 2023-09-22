#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long result;
int C[1001][1001];
int cost, node1, node2;
int parent[1001];
vector<pair<int, pair<int, int>>> v;

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> C[i][j];
            if (i < j)
                v.push_back({C[i][j], {i, j}});
        }
        parent[i] = i;
    }
}
int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
void Union(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cost = v[i].first;
        node1 = v[i].second.first;
        node2 = v[i].second.second;
        if (findParent(node1) != findParent(node2))
        {
            result += cost;
            Union(node1, node2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%lld\n", result);
}