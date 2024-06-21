// #include <iostream>
// #include <algorithm>
// #include <math.h>
// #include <queue>
// using namespace std;

// int n, ret;
// double num;
// priority_queue<pair<double, pair<int, int>>> pq;
// int dp[1010];

// void init()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> num;
//         pq.push({(num / i), {i, num}});

//     }
// }

// void solution()
// {
//     while (pq.size())
//     {
//         int numOfCards = pq.top().second.first;
//         int pay = pq.top().second.second;
//         pq.pop();

//         if (n < numOfCards)
//             continue;

//         while (n >= numOfCards)
//         {
//             n -= numOfCards;
//             ret += pay;
//         }
//         if (n == 0)
//             break;
//     }
//     cout << ret << "\n";
// }

// int main()
// {
//     init();
//     solution();
// }

#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int n, ret;
int arr[1010];
int dp[1010][1010];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = arr[i];
        for (int j = 1; j <= n; j++)
        {
            if(j<=i)
                dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j], dp[i][j - i] + arr[i]);
        }
    }
    cout << dp[n][n] << "\n";
}

int main()
{
    init();
    solution();
}