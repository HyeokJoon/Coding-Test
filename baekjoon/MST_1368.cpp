#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;
int W[301][301];
int cost, cur, _next;
// <cost, <cur, next>>
vector<pair<int, pair<int, int>>> v;
int parent[301];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i][i];
        v.push_back({W[i][i], {0, i}});
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> W[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            v.push_back({W[i][j], {i, j}});
        }
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
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        cost = v[i].first;
        cur = v[i].second.first;
        _next = v[i].second.second;
        // cur의 부모가 next의 부모와 같으면 넘어감 (사이클 생김)
        if (findParent(cur) != findParent(_next))
        {
            result += cost;
            Union(cur, _next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solution();
    printf("%d\n", result);
}