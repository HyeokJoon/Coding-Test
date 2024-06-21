#include <iostream>
using namespace std;

int t, n;
int dp[100010][4];

// dp[n] = dp[n - 1]
int solution(int n, int k)
{
    if (dp[n][k])
        return dp[n][k];

    int sum = 0;

    // dp[n][k] += (dp[n - 1][2] + dp[n - 1][3]) % 1000000009;
    // dp[n][k] += (dp[n - 2][1] + dp[n - 2][3]) % 1000000009;
    // dp[n][k] += (dp[n - 3][1] + dp[n - 3][2]) % 1000000009;
    for (int i = 1; i < 4; i++)
    {
        if (i != k && n - k > 0)
            sum += solution(n - k, i) % 1000000009;
    }
    dp[n][k] = sum;
    return dp[n][k];
}

void init()
{
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
}

int main()
{
    cin >> t;
    init();
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        int ret = 0;
        for (int i = 1; i < 4; i++)
        {
            ret += solution(n, i) % 1000000009;
        }
        cout << ret << "\n";
    }
}