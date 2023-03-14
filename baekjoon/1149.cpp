#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define R 0
#define G 1
#define B 2

int house[3][MAX_N]; // 0, 1, 2 = red, green, blue
int dic[3][MAX_N];

int min_three(int num1, int num2, int num3)
{
    if (num1 < num2)
    {
        if (num1 < num3)
        {
            return num1;
        }
        return num3;
    }
    if (num2 < num3)
    {
        return num2;
    }
    return num3;
}

int cost(int color, int i)
{

    if (dic[color][i])
    {
        return dic[color][i];
    }
    else if (i == 0)
    {
        dic[color][i] = house[color][0];
        return dic[color][i];
    }
    if (color == R)
    {
        dic[color][i] = min(cost(G, i - 1) + house[R][i],
                            cost(B, i - 1) + house[R][i]);
    }
    else if (color == G)
    {
        dic[color][i] = min(cost(R, i - 1) + house[G][i],
                            cost(B, i - 1) + house[G][i]);
    }
    else
    {
        dic[color][i] = min(cost(R, i - 1) + house[B][i],
                            cost(G, i - 1) + house[B][i]);
    }
    return dic[color][i];
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dic[j][i] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &house[j][i]);
        }
    }

    int result = min_three(cost(R, N - 1), cost(G, N - 1), cost(B, N - 1));
    printf("%d", result);
}
