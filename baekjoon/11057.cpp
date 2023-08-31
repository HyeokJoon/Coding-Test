/*
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.
*/

#include <iostream>
using namespace std;
long long N, result;
long long dp[1010][10];

// nCr = n-1Cr-1 + n-1Cr
long long combination(int n, int r)
{
    if (n == 0 || n < r)
        return 0;
    if (dp[n][r] != 0)
    {
        return dp[n][r];
    }
    else
    {
        dp[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r)) % 10007;
        return dp[n][r];
    }
}
// 1
// 11
// 121
// 1331
void init()
{
    for (int i = 0; i < 1002; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = 0;
        }
    }
}
int main()
{
    cin >> N;
    int n, r;

    init();
    result = combination(N + 9, 9);
    printf("%lld\n", result);
}