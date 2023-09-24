#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
int visited[11][11][11][11];
int clear;
int Rx, Ry, Bx, By;
string s;
queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = s[j];
            if (s[j] == 'R')
            {
                Rx = i;
                Ry = j;
            }
            else if (s[j] == 'B')
            {
                Bx = i;
                By = j;
            }
        }
    }
    visited[Rx][Ry][Bx][By] = 1;
    q.push({0, {{Rx, Ry}, {Bx, By}}});
}
void moveLeft(int rx, int ry, int bx, int by, int cnt)
{
    int meetR = 0, meetB = 0; // R이 B를 만날 때 , B가 R을 만날 때
    int goalR = 0, goalB = 0;
    while (map[rx][ry] != '#')
    {
        if (map[rx][ry] == 'O')
            goalR = 1;
        ry--;
        if (rx == bx && ry == by)
        {
            meetR = 1;
        }
    }
    ry++;
    while (map[bx][by] != '#')
    {
        if (map[bx][by] == 'O')
            goalB = 1;
        by--;
        if (rx == bx && ry == by)
        {
            meetB = 1;
        }
    }
    by++;
    if (goalR == 1 && goalB == 0)
        clear = 1;
    if (meetR == 1)
        ry++;
    else if (meetB == 1)
        by++;
    if (visited[rx][ry][bx][by] == 0 && goalB == 0)
    {
        q.push({cnt, {{rx, ry}, {bx, by}}});
        visited[rx][ry][bx][by] = 1;
    }
}
void moveRight(int rx, int ry, int bx, int by, int cnt)
{
    int meetR = 0, meetB = 0; // R이 B를 만날 때 , B가 R을 만날 때
    int goalR = 0, goalB = 0;
    while (map[rx][ry] != '#')
    {
        if (map[rx][ry] == 'O')
            goalR = 1;
        ry++;
        if (rx == bx && ry == by)
        {
            meetR = 1;
        }
    }
    ry--;
    while (map[bx][by] != '#')
    {
        if (map[bx][by] == 'O')
            goalB = 1;
        by++;
        if (rx == bx && ry == by)
        {
            meetB = 1;
        }
    }
    by--;
    if (goalR == 1 && goalB == 0)
        clear = 1;
    if (meetR == 1)
        ry--;
    else if (meetB == 1)
        by--;
    if (visited[rx][ry][bx][by] == 0 && goalB == 0)
    {
        q.push({cnt, {{rx, ry}, {bx, by}}});
        visited[rx][ry][bx][by] = 1;
    }
}
void moveUp(int rx, int ry, int bx, int by, int cnt)
{
    int meetR = 0, meetB = 0; // R이 B를 만날 때 , B가 R을 만날 때
    int goalR = 0, goalB = 0;
    while (map[rx][ry] != '#')
    {
        if (map[rx][ry] == 'O')
            goalR = 1;
        rx--;
        if (rx == bx && ry == by)
        {
            meetR = 1;
        }
    }
    rx++;
    while (map[bx][by] != '#')
    {
        if (map[bx][by] == 'O')
            goalB = 1;
        bx--;
        if (rx == bx && ry == by)
        {
            meetB = 1;
        }
    }
    bx++;
    if (goalR == 1 && goalB == 0)
        clear = 1;
    if (meetR == 1)
        rx++;
    else if (meetB == 1)
        bx++;
    if (visited[rx][ry][bx][by] == 0 && goalB == 0)
    {
        q.push({cnt, {{rx, ry}, {bx, by}}});
        visited[rx][ry][bx][by] = 1;
    }
}
void moveDown(int rx, int ry, int bx, int by, int cnt)
{
    int meetR = 0, meetB = 0; // R이 B를 만날 때 , B가 R을 만날 때
    int goalR = 0, goalB = 0;
    while (map[rx][ry] != '#')
    {
        if (map[rx][ry] == 'O')
            goalR = 1;
        rx++;
        if (rx == bx && ry == by)
        {
            meetR = 1;
        }
    }
    rx--;
    while (map[bx][by] != '#')
    {
        if (map[bx][by] == 'O')
            goalB = 1;
        bx++;
        if (rx == bx && ry == by)
        {
            meetB = 1;
        }
    }
    bx--;
    if (goalR == 1 && goalB == 0)
        clear = 1;
    if (meetR == 1)
        rx--;
    else if (meetB == 1)
        bx--;
    if (visited[rx][ry][bx][by] == 0 && goalB == 0)
    {
        q.push({cnt, {{rx, ry}, {bx, by}}});
        visited[rx][ry][bx][by] = 1;
    }
}
int solution()
{
    int cnt = 0;
    while (!q.empty())
    {
        Rx = q.front().second.first.first;
        Ry = q.front().second.first.second;
        Bx = q.front().second.second.first;
        By = q.front().second.second.second;
        cnt = q.front().first;
        q.pop();
        cnt++;
        moveLeft(Rx, Ry, Bx, By, cnt);
        if (clear == 1)
            return cnt;
        moveRight(Rx, Ry, Bx, By, cnt);
        if (clear == 1)
            return cnt;
        moveUp(Rx, Ry, Bx, By, cnt);
        if (clear == 1)
            return cnt;
        moveDown(Rx, Ry, Bx, By, cnt);
        if (clear == 1)
            return cnt;
        if (cnt > 10)
            return -1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int result = solution();
    printf("%d\n", result);
}