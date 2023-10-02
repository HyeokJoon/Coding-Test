#include <iostream>
using namespace std;

int k;
int arr[14];
int S[14];
int visited[14];

void init()
{
    for (int i = 0; i < 14; i++)
    {
        S[i] = 0;
        arr[i] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> S[i];
    }
}

void dfs(int cnt, int start)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i < k; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                arr[cnt] = S[i];
                dfs(cnt + 1, i);
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        init();
        dfs(0, 0);
        printf("\n");
    }
}