#include <iostream>
#include <map>
using namespace std;

map<string, int> in;
map<string, int> out;
map<string, int> visited;
string names[100001];
int namecount;
string s, e, q;
string t, name;
void init()
{
    cin >> s >> e >> q;
    while (cin >> t)
    {
        // cin >> t;
        cin >> name;
        names[namecount++] = name;
        if (t <= s)
        {
            in[name] = 1;
        }
        else if (t >= e && t <= q)
        {
            out[name] = 1;
        }
        else
            continue;
    }
}
void solution()
{
    int cnt = 0;
    for (int i = 0; i < namecount; i++)
    {
        if (in[names[i]] && out[names[i]] && visited[names[i]] == 0)
        {
            visited[names[i]] = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

int main()
{
    init();
    solution();
}