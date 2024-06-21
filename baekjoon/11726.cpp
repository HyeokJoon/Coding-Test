#include <iostream>
#include <queue>
using namespace std;

int N;
int dp[1001];

int solution(int n)
{
    dp[1] = 1;
    dp[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    // if (dp[n])
    // {
    //     return dp[n];
    // }
    // dp[n] = (solution(n - 1) + solution(n - 2))%10007;
    return dp[n];
}

int main()
{
    cin >> N;
    int ret = solution(N);
    cout << ret << "\n";
}




// int parent[1000];

// int findParent(int x)
// {
//     if (parent[x] == x)
//         return x;
//     else
//         return parent[x] = findParent(parent[x]);
// }

// void unionParent(int a, int b)
// {
//     a = findParent(a);
//     b = findParent(b);
//     if (a > b)
//         parent[a] = b;
//     else
//         parent[b] = a;
// }

// int main()
// {
//     int answer, cnt, V;
//     vector<pair<int, pair<int, int>>> v;
//     sort(v.begin(), v.end(), greater<>());
//     for (int i = 0; i < v.size(); i++)
//     {
//         pair<int, pair<int, int>> curEdge = v[i];
//         int cost = curEdge.first;
//         int now = curEdge.second.first;
//         int next = curEdge.second.second;

//         if (findParent(now) == findParent(next))
//             continue;
//         unionParent(now, next);
//         answer += cost;

//         if (++cnt == V - 1)
//             break;
//     }
// }
// struct compare
// {
//     bool operator()(pair<int, int> a, pair<int, int> b)
//     {
//         return a.second > b.second;
//     }
// };

// priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

// int Dist[1000];
// int INF = 987654321;
// void Prim()
// {
//     fill_n(Dist, 1000, INF);
// }