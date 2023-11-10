#include <iostream>
using namespace std;

string s;
int main()
{
    string temp;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] < 'N')
            temp += (s[i] + 13);
        else if (s[i] >= 'N' && s[i] <= 'Z')
            temp += s[i] - 13;
        else if (s[i] >= 'a' && s[i] < 'n')
            temp += s[i] + 13;
        else if (s[i] >= 'n' && s[i] <= 'z')
            temp += s[i] - 13;
        else
            temp += s[i];
    }
    cout << temp;
}