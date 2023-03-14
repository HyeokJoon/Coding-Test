#include <iostream>
#include <algorithm>
using namespace std;

int dic[1000001] = {0};

int fib(int n)
{
    if (dic[n])
    {
        return dic[n];
    }
    else if (n == 0 || n == 1)
    {
        dic[n] = n;
        return n;
    }
    else
    {
        dic[n] = fib(n - 1) + fib(n - 2);
        if (dic[n] >= 1000000000)
        {
            dic[n] -= 1000000000;
        }
        return dic[n];
    }
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    int n, result;

    scanf("%d", &n);
    if (n > 0)
        printf("1\n%d", fib(n));
    else if (n == 0)
        printf("0\n%d", fib(n));
    else
    {
        if (abs(n) % 2 == 0)
        {
            printf("-1\n%d", fib(abs(n)));
        }
        else
            printf("1\n%d", fib(abs(n)));
    }
}
