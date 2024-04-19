#include <iostream>
using namespace std;

int N;
int dp[1001];

int solution(int n)
{
    dp[1] = 1;
    dp[0] = 1;
    if (dp[n])
    {
        return dp[n];
    }
    dp[n] = (solution(n - 1) + solution(n - 2))%10007;
    return dp[n];
}

int main()
{
    cin >> N;
    int ret = solution(N);
    cout << ret << "\n";
}