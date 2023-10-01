#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string S, T;
string s1, s2;
queue<string> q;

int solution()
{
    while (!q.empty())
    {
        s1 = q.front();
        s2 = q.front();
        q.pop();
        if (s1.size() > S.size())
        {
            if (s1[s1.size() - 1] == 'A')
            {
                q.push(s1.erase(s1.size() - 1));
            }
            if (s2[0] == 'B')
            {
                reverse(s2.begin(), s2.end());
                q.push(s2.erase(s2.size() - 1));
            }
        }
        else if (s1 == S)
            return 1;
    }
    return 0;
}

int main()
{
    cin >> S >> T;
    q.push(T);
    printf("%d\n", solution());
}