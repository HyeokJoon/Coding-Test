#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;
vector<pair<int, int>> xpoint;
vector<pair<int, int>> ypoint;
vector<pair<int, int>> zpoint;
vector<pair<int, pair<int, int>>> planet;
int parent[100001];

void init()
{
    cin >> N;
    int x, y, z;
    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y >> z;
        xpoint.push_back({x, i});
        ypoint.push_back({y, i});
        zpoint.push_back({z, i});
        parent[i] = i;
    }
    sort(xpoint.begin(), xpoint.end());
    sort(ypoint.begin(), ypoint.end());
    sort(zpoint.begin(), zpoint.end());
    for (int i = 0; i < xpoint.size() - 1; i++)
    {
        planet.push_back({xpoint[i + 1].first - xpoint[i].first, {xpoint[i].second, xpoint[i + 1].second}});
        planet.push_back({ypoint[i + 1].first - ypoint[i].first, {ypoint[i].second, ypoint[i + 1].second}});
        planet.push_back({zpoint[i + 1].first - zpoint[i].first, {zpoint[i].second, zpoint[i + 1].second}});
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
    sort(planet.begin(), planet.end());
    for (int i = 0; i < planet.size(); i++)
    {
        int cost = planet[i].first;
        int n1 = planet[i].second.first;
        int n2 = planet[i].second.second;
        if (findParent(n1) != findParent(n2))
        {
            unionParent(n1, n2);
            result += cost;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%d\n", result);
}