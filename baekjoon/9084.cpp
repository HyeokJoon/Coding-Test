#include <iostream>
using namespace std;
int T, N, M, result;
int coins[21];
int dp[10001];

void init()
{

    cin >> N;
    for (int j = 1; j <= N; j++)
    {
        cin >> coins[j];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
}

// solution(n) = for in coins (solution(n-coins[i])+1)
int solution()
{ // n을 만드는 개수
    for (int i = 1; i <= N; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= M; j++) // 자기 자신보다 큰 수를 만들 수 있음
        {
            dp[j] += dp[j - coin];
        }
    }
    return dp[M];
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        init();
        result = solution();
        printf("%d\n", result);
    }
}