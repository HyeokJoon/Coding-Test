#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, result;
int a, b, c;
int first_c;
vector<pair<int, pair<int, int>>> v;
int parent[1001];
int _max, _min;
int cost, n1, n2;

void init()
{
    cin >> N >> M;
    for (int i = 0; i <= M; i++)
    {
        cin >> a >> b >> c;
        if (i == 0)
        {
            first_c = c;
            continue;
        }
        v.push_back({c, {a, b}});
    }
    for (int i = 1; i <= N; i++)
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
        n1 = v[i].second.first;
        n2 = v[i].second.second;
        if (findParent(n1) != findParent(n2))
        {
            unionParent(n1, n2);
            if (cost == 0)
                _max++;
        }
    }
    if (first_c == 0)
        _max++;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < v.size(); i++)
    {
        cost = v[i].first;
        n1 = v[i].second.first;
        n2 = v[i].second.second;
        if (findParent(n1) != findParent(n2))
        {
            unionParent(n1, n2);
            if (cost == 0)
                _min++;
        }
    }
    if (first_c == 0)
        _min++;

    result = (_max * _max) - (_min * _min);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%d\n", result);
}