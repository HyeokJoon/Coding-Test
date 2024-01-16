#include <iostream>
#include <algorithm>
using namespace std;

int t, s, e;
int sx, sy, ex, ey;

void init()
{
    cin >> s >> e;
    int i = 1, sum = 0;
    bool sFlag = true, eFlag = true;
    while (1)
    {
        sum += i;
        if (sFlag && s <= sum)
        {
            // cout << "Ssum : " << sum << endl;
            sFlag = false;
            sx = i;
            sy = i - (sum - s);
            // cout << sx << " , " << sy << endl;
        }
        if (eFlag && e <= sum)
        {
            // cout << "Esum : " << sum << endl;
            eFlag = false;
            ex = i;
            ey = i - (sum - e);

            // cout << ex << " , " << ey << endl;
        }
        if (eFlag == false && sFlag == false)
            break;
        i++;
    }
}
int solution()
{
    int dx = ex - sx;
    int dy = ey - sy;
    // 부호가 같을때
    if (dx * dy > 0)
    {
        return max(abs(dx), abs(dy));
    }
    //부호가 다를 때
    else
    {
        return abs(dx) + abs(dy);
    }
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        int result = solution();
        printf("#%d %d\n", i, result);
    }
}