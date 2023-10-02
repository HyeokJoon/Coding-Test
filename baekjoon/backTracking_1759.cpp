#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> arr;
char answer[16];
int visited[30];

void init()
{
    cin >> L >> C;
    char c;
    for (int i = 0; i < C; i++)
    {
        cin >> c;
        arr.push_back(c);
    }
}
bool usable()
{
    int m = 0;
    int j = 0;
    for (int i = 0; i < L; i++)
    {
        if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u')
        {
            m++;
        }
        else
            j++;
    }
    if (m < 1 || j < 2)
        return false;
    return true;
}
void dfs(int cnt, int idx)
{
    sort(arr.begin(), arr.end());
    if (cnt == L)
    {
        if (!usable())
            return;
        for (int i = 0; i < L; i++)
        {
            printf("%c", answer[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = idx; i < C; i++)
        {
            if (!visited[arr[i] - 'a'])
            {
                visited[arr[i] - 'a'] = 1;
                answer[cnt] = arr[i];
                dfs(cnt + 1, i);
                visited[arr[i] - 'a'] = 0;
            }
        }
    }
}

int main()
{
    init();
    dfs(0, 0);
}