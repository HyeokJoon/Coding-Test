#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ret = 0;
    int bar_cnt = 0;
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            bar_cnt++;
            flag = 1;
        }
        else
        {
            if (flag)
            {
                bar_cnt--;
                ret += bar_cnt;
                flag = 0;
            }
            else
            {
                bar_cnt--;
                ret += 1;
            }
        }
    }
    cout << ret;
}