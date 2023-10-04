#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<string, string, greater<>> m;
void init()
{
    cin >> n;
    string name;
    string state;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> state;
        m[name] = state;
    }
}
void solution()
{
    string result;
    map<string, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->second == "enter")
        {
            cout << it->first << "\n";
        }
    }
}

int main()
{
    init();
    solution();
}