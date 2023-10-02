#include <iostream>
using namespace std;

int N;
int col[16];
int total;

bool check(int x)
{
    for (int i = 0; i < x; i++)
    {
        // 같은 행이 다른 열 을 가지고 있을 때 || 대각선에 있을 때
        if (col[i] == col[x] || (x - i) == abs(col[x] - col[i]))
            return false;
    }
    return true;
}

void dfs(int x)
{
    if (x == N)
    {
        total++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
                dfs(x + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dfs(0);
    printf("%d\n", total);
}