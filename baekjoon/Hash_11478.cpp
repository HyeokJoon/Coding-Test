#include <iostream>
#include <map>
using namespace std;

string s;
map<string, int> m;
void init()
{
    cin >> s;
}
void solution()
{
    string sub;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sub = s[i];
        if (m[sub] == 0)
        {
            m[sub] = 1;
            cnt++;
        }
        for (int j = i + 1; j < s.size(); j++)
        {
            sub += (s[j]);
            if (m[sub] == 0)
            {
                m[sub] = 1;
                cnt++;
            }
        }
    }
    // printf("%d\n", m.size());
    printf("%d\n", cnt);
}

int main()
{
    init();
    solution();
}