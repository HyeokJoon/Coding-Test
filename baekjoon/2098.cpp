#include <iostream>
using namespace std;

const int INF = 987654321;

int dp[16][1<<16];
int N;
int w[17][17];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> w[i][j];
        }
    }

    memset(dp,-1, sizeof(dp));

}