#include <iostream>
using namespace std;

string s;
int main()
{
    cin >> s;
    int answer = 1;
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        // cout << s[start] << ' ' << s[end] << endl;
        if (s[start++] != s[end--])
        {
            answer = 0;
            break;
        }
    }
    cout << answer;
}