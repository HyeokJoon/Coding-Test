#include <iostream>
#include <set>
using namespace std;

int main()
{
    int s1, s2, a;
    cin >> s1 >> s2;
    set<int> S1;
    int cnt = 0;
    for (int i = 0; i < s1; i++)
    {
        cin >> a;
        S1.insert(a);
    }
    for (int i = 0; i < s2; i++)
    {
        cin >> a;
        if (S1.find(a) != S1.end())
            cnt++;
    }
    cout << s1 + s2 - cnt - cnt;
}