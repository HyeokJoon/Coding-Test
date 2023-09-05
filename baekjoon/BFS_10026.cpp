#include <iostream>
#include <queue>
using namespace std;

int N, cnt_n, cnt_s;
char map[102][102];
int visited_n[102][102];
int visited_s[102][102];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string s;
char cur;

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            map[i][j + 1] = s[j];
        }
    }
}
void normal(int a, int b)
{
    visited_n[a][b] = 1;
    q.push(make_pair(a, b));
    cnt_n++;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cur = map[x][y];
        for (int i = 0; i < 4; i++)
        { // 갈 수 있으면
            if (visited_n[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == cur)
            {
                q.push(make_pair(x + dx[i], y + dy[i]));
                visited_n[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
}

void special(int a, int b)
{
    visited_s[a][b] = 1;
    q.push(make_pair(a, b));
    cnt_s++;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cur = map[x][y];

        for (int i = 0; i < 4; i++)
        { // 갈 수 있으면
            if (cur != 'B')
            {
                if (visited_s[x + dx[i]][y + dy[i]] == 0 && (map[x + dx[i]][y + dy[i]] == 'R' || map[x + dx[i]][y + dy[i]] == 'G'))
                {
                    q.push(make_pair(x + dx[i], y + dy[i]));
                    visited_s[x + dx[i]][y + dy[i]] = 1;
                }
            }
            else if (visited_s[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == cur)
            {
                q.push(make_pair(x + dx[i], y + dy[i]));
                visited_s[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
}

int main()
{
    init();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visited_n[i][j] == 0)
            {
                normal(i, j);
            }
            if (visited_s[i][j] == 0)
            {
                special(i, j);
            }
        }
    }
    printf("%d %d\n", cnt_n, cnt_s);
}