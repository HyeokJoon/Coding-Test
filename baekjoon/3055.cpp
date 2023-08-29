#include <iostream>
using namespace std;

int R, C;
char map[55][55] = {'0'};
bool canMove[55][55] = {false};
int water[55][55] = {0};

int Dx, Dy, Sx, Sy;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init()
{
    char c;
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> c;
            map[i][j] = c;
            if (c == 'S')
            {
                Sx = i;
                Sy = j;
            }
            else if (c == 'D')
            {
                Dx = i;
                Dy = j;
            }
            else if (c == '*')
            {
                water[i][j] = 1;
            }
            else
            {
            }
        }
    }
}

void moveWater()
{
    for (int i = 0; i <)
    {
    }
}

void move()
{
}

int main()
{
    freopen("beakjoon/input", "r", stdin);
    init();
}