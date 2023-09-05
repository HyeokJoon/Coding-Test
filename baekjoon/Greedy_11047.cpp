#include <iostream>
using namespace std;

int N, K, sum;
int value[10];

void init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
    }
}

void solution()
{
    for (int i = N - 1; i >= 0; i--)
    {
        sum += K / value[i];
        K %= value[i];
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", sum);
}