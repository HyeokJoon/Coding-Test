#include <iostream>
using namespace std;

int n, m;
int _max;
int map[1010][1010];
string c;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        for (int j = 0; j < m; j++)
        {
            map[i][j + 1] = (int)c[j] - '0';
        }
    }
}
// 00
// 00
// 01
// 01
// dp[i][j][n] = dp[i][j][n-1], dp[i+1][j][n-1], dp[i][j+1][n-1], dp[i-1][j-1][n-1]
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] != 0)
            {
                map[i][j] += min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1]));
                if (map[i][j] > _max)
                    _max = map[i][j];
            }
        }
    }
}

int main()
{
    init();
    solution();
    printf("%d\n", _max * _max);
}