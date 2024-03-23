#include <iostream>
using namespace std;

int n, sum, ret;
int maxi = 0, mini;
char map[21][21];
//행 1,2,3 열 1,2,3  >>>>> 111111비트 마스킹
int main()
{
    cin >> n;
    char a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (a == 'T')
            {
                ret += 1;
                map[i][j] = 1;
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }
    sum = mini = ret;
    //전체 경우의 수
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < n; k++)
                {
                    if (map[j][k])
                    {
                        map[j][k] = 0;
                        sum--;
                    }
                    else
                    {
                        map[j][k] = 1;
                        sum++;
                    }
                }
            }
        }
        maxi = max(sum, maxi);
        mini = min(mini, sum);
    }
    ret = min((n * n - maxi), mini);
    cout << ret << "\n";
}