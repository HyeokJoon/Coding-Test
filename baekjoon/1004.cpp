#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int cnt = 0;
        int x1, y1, x2, y2, p;
        cin >> x1 >> y1 >> x2 >> y2 >> p;
        int cx, cy, r;
        for (int j = 0; j < p; j++)
        {
            cin >> cx >> cy >> r;
            //출발점만 원 안에 있는 경우의 수
            double l1 = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy));
            double l2 = sqrt((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy));
            if (r > l1 && r < l2)
                cnt++;
            //도착점만 원 안에 있는 경우의 수
            else if (r > l2 && r < l1)
                cnt++;
        }
        cout << cnt << endl;
    }
}