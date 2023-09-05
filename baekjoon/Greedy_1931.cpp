#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cnt = 1;
vector<pair<int, int>> v;

void init()
{
    cin >> N;
    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        v.push_back(make_pair(e, s));
    }
}
void solution()
{
    sort(v.begin(), v.end());
    int t = v[0].first;

    for (int i = 1; i < N; i++)
    {
        if (t <= v[i].second)
        {
            cnt++;
            t = v[i].first;
        }
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", cnt);
}