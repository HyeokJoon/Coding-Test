#include <iostream>
#include <queue>
using namespace std;

int N, K, L, flag;
int apple[101][101];
int visited[101][101];
//아래, 왼쪽, 위, 오른쪽
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int now_sec = 0;
int now_D = 3;
int posx = 1, posy = 1;
vector<pair<int, char>> v;
queue<pair<int, int>> q;

void init()
{
    cin >> N >> K;
    int x, y;
    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        apple[x][y] = 1;
    }
    cin >> L;
    int X;
    char C;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> C;
        v.push_back({X, C});
    }
    visited[1][1] = 1;
    q.push({1, 1});
}
void move()
{
    int x = posx + dx[now_D];
    int y = posy + dy[now_D];
    if (visited[x][y]) // 몸이 있으면
    {
        flag = 1;
        return;
    }
    if (x == 0 || x > N || y == 0 || y > N) //벽에 닿으면
    {
        flag = 1;
        return;
    }
    if (apple[x][y] == 1) // 사과가 있으면
        apple[x][y] = 0;
    else
    {
        int tailx = q.front().first;
        int taily = q.front().second;
        q.pop();
        visited[tailx][taily] = 0;
    }
    posx = x;
    posy = y;
    visited[posx][posy] = 1;
    q.push({posx, posy});
}
void changeDirect(char D)
{
    if (D == 'L')
    {
        now_D--;
        now_D += 4;
        now_D %= 4;
    }
    else
    {
        now_D++;
        now_D %= 4;
    }
}

void solution()
{
    for (int i = 0; i < v.size(); i++)
    {
        int next_sec = v[i].first;
        char next_D = v[i].second;
        while (next_sec > now_sec)
        {
            now_sec++;
            move();
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
        changeDirect(next_D);
    }
    while (flag == 0)
    {
        now_sec++;
        move();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%d\n", now_sec);
}