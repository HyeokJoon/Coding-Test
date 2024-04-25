#include <iostream>
using namespace std;
int t, num;
pair<int, int> dp[41];

void init()
{
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for (int i = 2; i <= 40; i++)
    {
        dp[i] = {dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second};
    }
}

int main()
{
    cin >> t;
    init();
    for (int tc = 0; tc < t; tc++)
    {
        cin >> num;
        cout << dp[num].first << ' ' << dp[num].second << "\n";
    }
}