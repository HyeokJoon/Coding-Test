#include <iostream>
using namespace std;

int T, n, cnt;
int dp[10001][4];

void init()
{
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < 10001; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][2] + dp[i - 2][1];
        if (i > 2)
        {
            dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
        }
    }
}
int main()
{
    init();
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        int result = dp[n][1] + dp[n][2] + dp[n][3];
        printf("%d\n", result);
    }
}