#include <iostream>
using namespace std;
int n, k, result;
int coins[101];
int dp[10001];

void init()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
}

int solution()
{
    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    return dp[k];
}

int main()
{
    init();
    result = solution();
    printf("%d\n", result);
}