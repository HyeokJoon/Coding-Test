#include <iostream>
#include <queue>
using namespace std;

char num_c[5];
int num_i;
int cnt;
queue<char> q;

void init()
{
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            continue;
        q.push(c);
    }
}

int nextNum()
{
    while (!q.empty())
    {
        char c = q.front();
        if (c >= '0' && c <= '9')
        {
            num_c[cnt++] = c;
            q.pop();
        }
        else
        {
            num_i = stoi(num_c);
            for (int i = 0; i < 5; i++)
            {
                num_c[i] = '\0';
            }
            cnt = 0;
            return num_i;
        }
    }
    num_i = stoi(num_c);
    for (int i = 0; i < 5; i++)
    {
        num_c[i] = '\0';
    }
    cnt = 0;
    return num_i;
}

int calc()
{
    int num = nextNum();
    while (!q.empty())
    {
        char c = q.front();
        if (c == '+')
        {
            q.pop();
            num += nextNum();
        }
        else if (c == '-')
        {
            while (!q.empty())
            {
                q.pop();
                num = num - nextNum();
            }
        }
    }
    return num;
}

int main()
{
    init();
    int result = calc();
    printf("%d\n", result);
}