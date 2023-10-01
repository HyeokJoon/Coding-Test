#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[10];
int visited[10];

void init()
{
    cin >> N >> M;
}
void dfs(int cnt) // 이게 백트래킹 기본
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    // 이걸 stack으로 쓸 수도 있음
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = 0;
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