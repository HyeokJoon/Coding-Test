#include <iostream>
using namespace std;

int N;
int map[66][66];

void init()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
}

bool isNotOne(int n, int startR, int startC)
{
    int i = 0;
    int firstValue = map[startR][startC];
    while (i < n)
    {
        int j = 0;
        int r = startR + i;
        while (j < n)
        {
            int c = startC + j;
            if (map[r][c] != firstValue)
                return true;
            j++;
        }
        i++;
    }
    return false;
}

void solution(int n, int startR, int startC)
{
    if (isNotOne(n, startR, startC))
    {
        printf("(");
        solution(n / 2, startR, startC);                     // 왼쪽 위
        solution(n / 2, startR, startC + (n / 2));           // 오른쪽 위
        solution(n / 2, startR + (n / 2), startC);           // 왼쪽 아래
        solution(n / 2, startR + (n / 2), startC + (n / 2)); // 오른쪽 아래
        printf(")");
    }
    else
        printf("%d", map[startR][startC]);
}

int main()
{
    init();
    solution(N, 0, 0);
}