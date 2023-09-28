#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N, M, r, c, K, x, y;
int map[21][21];
vector<int> dice(7); // index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면
int up, down, e, w, n, s;
deque<int> row;
deque<int> col;
vector<int> v;

void init()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    int a;
    for (int k = 0; k < K; k++)
    {
        cin >> a;
        v.push_back(a);
    }
}

void moveDice(int a)
{
    if (a == 1) // 동
    {
        if (y + 1 == M) // 바깥이면
            return;
        y++;
        dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
        if (map[x][y] == 0) //바닥면이 0이면 복사
        {
            map[x][y] = dice[6];
        }
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        printf("%d\n", dice[1]);
    }
    else if (a == 2) // 서
    {
        if (y == 0)
            return;
        y--;
        dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
        if (map[x][y] == 0) //바닥면이 0이면 복사
        {
            map[x][y] = dice[6];
        }
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        printf("%d\n", dice[1]);
    }
    else if (a == 3) // 북
    {
        if (x == 0)
            return;
        x--;
        dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
        if (map[x][y] == 0) //바닥면이 0이면 복사
        {
            map[x][y] = dice[6];
        }
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        printf("%d\n", dice[1]);
    }
    else // 남
    {
        if (x + 1 == N)
            return;
        x++;
        dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
        if (map[x][y] == 0) //바닥면이 0이면 복사
        {
            map[x][y] = dice[6];
        }
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        printf("%d\n", dice[1]);
    }
}

void solution()
{
    for (int i = 0; i < v.size(); i++)
    {
        moveDice(v[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
}