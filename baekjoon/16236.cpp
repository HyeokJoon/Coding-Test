#include <iostream>
using namespace std;
#define MAX_N 22

class Fish
{
    int x, y, size;
};

int map[MAX_N][MAX_N];
int N;
int shark_x, shark_y;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
            {
                map[i][j] = 0;
            }
            else
            {
                cin >> map[i][j];
                if (map[i][j] == 9)
                {
                    shark_x = i;
                    shark_y = j;
                }
            }
        }
    }
}

Fish find()
{
    int dist = 1;
    for (int x = shark_x - dist; x < shark_x + dist; x++)
    {
        for (int y = shark_y - dist; y < shark_y + dist; y++)
        {
            if (map[x][y] != 0)
            {
            }
        }
    }
}

int main()
{
    init();
}