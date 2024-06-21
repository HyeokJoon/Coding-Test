#include <iostream>
#include <string>
using namespace std;

bool solution(string s)
{
    // 가운데를 포함하는 승리 경우
    cout << s[4] << ' ' << s[0] << ' ' << s[8] << endl;
    cout << (s[4] == 'O') << endl;
    if (s[4] != '.')
    {
        if (s[4] == s[0] && s[4] == s[8])
            return true;
        if (s[4] == s[1] && s[4] == s[7])
            return true;
        if (s[4] == s[2] && s[4] == s[6])
            return true;
        if (s[4] == s[3] && s[4] == s[5])
            return true;
    }
    // 외곽 승리 경우
    if (s[0] != '.')
    {
        if (s[0] == s[1] && s[0] == s[2])
            return true;
        if (s[0] == s[3] && s[0] == s[6])
            return true;
    }
    if (s[9] != '.')
    {
        if (s[9] == s[2] && s[9] == s[5])
            return true;
        if (s[9] == s[8] && s[9] == s[7])
            return true;
    }
    //  '.'이 없는 경우
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == '.')
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (1)
    {
        cin >> s;

        // for(int i=0; i<s.size(); i++){
        //     cout << s[i];
        // }

        if (s == "end")
        {
            break;
        }
        if (solution(s))
            cout << "valid"
                 << "\n";
        else
            cout << "invalid"
                 << "\n";
    }
}