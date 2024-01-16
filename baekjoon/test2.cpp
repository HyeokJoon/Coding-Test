#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int t, n, flag = 10000000, result, total, loss;
vector<pair<int, pair<int, int>>> v; // num, dead, idx
int maxi[51];
int dead[51];
int flags[3];

void init()
{
    total = 0;
    result = 0;
    flag = 10000000;
    loss = 0;

    cin >> n;
    int input;

    for (int i = 0; i < 51; i++)
    {
        maxi[i] = 0;
    }

    v.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cin >> input;
            v.push_back({input, {i, j}});
            maxi[i] = max(maxi[i], input);
            total += input;
        }
        loss += maxi[i];
    }
}

void combi(int start, vector<pair<int, pair<int, int>>> b)
{
    if (b.size() == 3)
    {
        result = 0;
        for (int i = 0; i < 3; i++)
        {
            result += maxi[b[i].second.first] - b[i].first; //손해보는 양
        }
        flag = min(flag, result);
    }
    else
    {
        for (int i = start + 1; i < v.size(); i++)
        {
            if (dead[v[i].second.first] == 0 && flags[v[i].second.second] == 0)
            {
                dead[v[i].second.first] = 1;
                flags[v[i].second.second] = 1;
                b.push_back(v[i]);
                combi(i, b);
                b.pop_back();
                dead[v[i].second.first] = 0;
                flags[v[i].second.second] = 0;
            }
        }
    }
}
int solution()
{
    vector<pair<int, pair<int, int>>> b;
    if (n < 3)
    {
        return -1;
    }
    else
    {
        sort(v.begin(), v.end(), greater<>());
        combi(-1, b);
        return total - loss + flag;
    }
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        printf("#%d %d\n", i, solution());
    }
}