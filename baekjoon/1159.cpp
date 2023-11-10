#include <iostream>

using namespace std;
int N;
int cnt[30];

int main()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 4)
        {
            cout << (char)(i + 'a');
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "PREDAJA";
}