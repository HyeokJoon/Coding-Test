#include <iostream>
using namespace std;

int N, M;
int arr[10];

void init()
{
    cin >> N >> M;
}

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            arr[cnt] = i;
            dfs(cnt + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    dfs(0);
}