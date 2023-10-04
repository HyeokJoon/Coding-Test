#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string s;
char map[7][7];
int visited[26];
int mm[7][7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;
int result;

void init()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            map[i][j] = s[j];
        }
    }
}

bool check()
{
    int numy = 0;
    int nums = 0;
    for (int i = 0; i < 7; i++)
    {
        int x = v[i] / 5;
        int y = v[i] % 5;
        if (map[x][y] == 'Y')
            numy++;
        else
            nums++;
    }
    if (nums < 4)
        return false;
    return true;
}

bool linked()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            mm[i][j] = 0;
    }
    queue<pair<int, int>> q;
    q.push({v[0] / 5, v[0] % 5});
    mm[v[0] / 5][v[0] % 5] = 1;
    int c = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx > 4 || yy < 0 || yy > 4)
                continue;
            if (visited[xx * 5 + yy] && mm[xx][yy] == 0)
            {
                mm[xx][yy] = 1;
                q.push({xx, yy});
                c++;
            }
        }
    }
    if (c == 7)
        return true;
    return false;
}
void dfs(int cnt, int num)
{
    if (cnt == 7)
    {
        if (check())
            if (linked())
                result++;
        return;
    }
    else
    {
        for (int i = num; i < 25; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                v.push_back(i);
                dfs(cnt + 1, i);
                v.pop_back();
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    init();
    dfs(0, 0);
    printf("%d\n", result);
}