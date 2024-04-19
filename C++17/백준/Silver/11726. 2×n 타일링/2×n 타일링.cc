#include <iostream>
using namespace std;

int N;
int dp[1001];

int solution(int n)
{
    dp[1] = 1;
    dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n];
}

int main()
{
    cin >> N;
    int ret = solution(N);
    cout << ret << "\n";
}