#include <iostream>
using namespace std;

long long N, B, C, result;
int A[1000001];

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> B >> C;
}
void solution()
{
    for (int i = 0; i < N; i++)
    {
        result++;
        int num = A[i];
        if (num <= B)
            continue;
        num -= B;
        if (num % C != 0)
        {
            num /= C;
            result += (num + 1);
        }
        else
        {
            num /= C;
            result += num;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%lld\n", result);
}