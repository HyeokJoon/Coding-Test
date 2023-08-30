/*
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
int N, t, result;
int dp[11];
// calc(n) = calc(n-1)+ calc(n-2), calc(n-3)
int calc(int n)
{
    if (dp[n] != 0)
        return dp[n];
    else
    {
        dp[n] = calc(n - 1) + calc(n - 2) + calc(n - 3);
        return dp[n];
    }
}

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> N;
        result = calc(N);
        printf("%d\n", result);
    }
}