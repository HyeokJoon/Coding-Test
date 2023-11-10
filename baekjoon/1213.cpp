#include <iostream>
#include <vector>

using namespace std;

int alpha[26];

void init()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'A']++;
    }
}

void solution()
{
    vector<char> v;
    char mid;
    int flag;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0)
            continue;
        //짝수이면 절반을 vector에 넣음
        if (alpha[i] % 2 == 0)
        {
            for (int j = 0; j < alpha[i] / 2; j++)
                v.push_back(i + 'A');
        }
        // 홀수이면 flag를 1로 하고 vector에 넣음
        else
        {
            if (flag == 1)
            {
                printf("I'm Sorry Hansoo");
                return;
            }
            flag = 1;
            mid = i + 'A';
            for (int j = 0; j < alpha[i] / 2; j++)
                v.push_back(i + 'A');
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        printf("%c", v[i]);
    }
    if (flag == 1)
        printf("%c", mid);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        printf("%c", v[i]);
    }
}

int main()
{
    init();
    solution();
}