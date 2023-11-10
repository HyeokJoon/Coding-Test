#include <iostream>
#include <vector>
using namespace std;

int N;

vector<char> patternS;
vector<char> patternE;

void init()
{
    cin >> N;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != '*')
    {
        patternS.push_back(s[i]);
        i++;
    }
    i++;
    for (i; i < s.size(); i++)
    {
        patternE.push_back(s[i]);
    }
}

// * 앞쪽이 같은지
bool checkFront(string s)
{
    for (int i = 0; i < patternS.size(); i++)
    {
        if (patternS[i] != s[i])
        {
            return false;
        }
    }
    return true;
}
// * 뒤쪽이 같은지
bool checkBack(string s)
{
    int idx = s.size() - patternE.size();
    for (int i = 0; i < patternE.size(); i++)
    {
        if (patternE[i] != s[idx + i])
        {
            return false;
        }
    }
    return true;
}

void solution()
{
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s.size() < patternE.size() + patternS.size())
        {
            cout << "NE"
                 << "\n";
            continue;
        }
        if (checkFront(s) && checkBack(s))
        {
            cout << "DA"
                 << "\n";
        }
        else
            cout << "NE"
                 << "\n";
    }
}

int main()
{
    init();
    solution();
}