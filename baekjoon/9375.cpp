
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, t;
map<string, int> m;
vector<string> v;

void init()
{
    m.clear();
    while (!v.empty())
        v.pop_back();
    cin >> n;
    string type, name;
    for (int i = 0; i < n; i++)
    {
        //의상 종류 별로 개수 확인
        cin >> name >> type;
        if (m[type] == 0)
        {
            v.push_back(type);
        }
        m[type]++;
    }
}

void solution()
{
    init();
    int result = 1;
    for (auto it : v)
    {
        int cnt = m[it];
        // 각각 옷 종류에서 1개를 뽑거나 안뽑거나
        result *= (cnt + 1);
    }
    printf("%d\n", result - 1);
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution();
    }
}