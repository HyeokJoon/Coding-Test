#include <iostream>
using namespace std;

int N;
int min_n = 2000000000;
int cur;
int arr[100000];
int liq1, liq2;

void init()
{
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        arr[i] = n;
    }
}
void check(int num1, int num2)
{
    cur = arr[num1] + arr[num2];
    if (abs(cur) < min_n)
    {
        min_n = abs(cur);
        liq1 = num1;
        liq2 = num2;
    }
}
void calc(int start, int end)
{
    while (1)
    {
        if (start >= end)
        {
            break;
        }
        check(start, end);
        if (cur < 0)
            start++;
        else
            end--;
    }
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    init();
    calc(0, N - 1);
    printf("%d %d\n", arr[liq1], arr[liq2]);
}