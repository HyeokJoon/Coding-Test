#include <iostream>
using namespace std;

int N, M;
int arr[10];
int visited[10];
void init()
{
    cin >> N >> M;
}

void dfs(int cnt, int num)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    for (int i = num; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(cnt + 1, i);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    dfs(0, 1);
}