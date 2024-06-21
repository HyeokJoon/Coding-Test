#include <iostream>
#include <algorithm>
using namespace std;

int x;
int ret;
int dp[3000001];

dp[10] = dp[7]+1, dp[8]+1, dp[9]+1
int calc(int x)
{
    for (int i = 0; i <= x; i++)
    {
        dp[i] = 200000;
    }

    dp[1] = 0;
    for (int i = 1; i <= x; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        dp[2 * i] = min(dp[2 * i], dp[i] + 1);
        dp[3 * i] = min(dp[3 * i], dp[i] + 1);
    }
    return dp[x];
}

int main()
{
    cin >> x;
    ret = calc(x);
    cout << ret << "\n";
}

// #include <iostream>
// using namespace std;
// int calc(int n);
// int N, result;
// int dp[1000001];

// // calc(n) = min(calc(n/3)+1, calc(n/2)+1, calc(n-1)+1)
// int min_tri(int a, int b, int c)
// {
//     if (a < b)
//     {
//         if (c < a)
//             return c;
//         else
//             return a;
//     }
//     else if (b < c)
//     {
//         return b;
//     }
//     return c;
// }

// int calc(int n)
// {
//     if (n == 1)
//         return 0;
//     else if (n == 2)
//         return 1;

//     else if (dp[n] != 0)
//         return dp[n];

//     else if (n % 3 == 0 && n % 2 == 0)
//     {
//         dp[n] = min_tri(calc(n / 3) + 1, calc(n / 2) + 1, calc(n - 1) + 1);
//         return dp[n];
//     }
//     else if (n % 3 == 0)
//     {
//         dp[n] = min(calc(n / 3) + 1, calc(n - 1) + 1);
//         return dp[n];
//     }
//     else if (n % 2 == 0)
//     {
//         dp[n] = min(calc(n / 2) + 1, calc(n - 1) + 1);
//         return dp[n];
//     }
//     else
//     {
//         dp[n] = calc(n - 1) + 1;
//         return dp[n];
//     }
// }

// int main()
// {
//     cin >> N;
//     result = calc(N);
//     printf("%d\n", result);
// }
