#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010]; // n개를 갖기 위한 최소금액
int n;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i];
}

// i개를 구매할 때 최소 금액 = i-j개의 최소금액 + j개의 금액
// Topdown : dp[i] = min(dp[i], dp[i-j] + dp[j])
// Bottomup : dp[i+j] = min(dp[i + j], dp[i] + dp[j])
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i + j > n)
                break;
            dp[i + j] = min(dp[i + j], dp[i] + dp[j]);
        }
    }
    cout << dp[n];
}

int main()
{
    init();
    solution();
}