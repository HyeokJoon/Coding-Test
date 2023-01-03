#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N, M;
    int cnt = 0;
    cin >> N >> M;
    map<string, int> m;
    string a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        m.insert({a, i});
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        if (m.find(a) != m.end())
        {
            cnt++;
        }
    }
    cout << cnt;
}