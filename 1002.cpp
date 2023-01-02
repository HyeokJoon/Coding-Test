#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    double x1, x2, y1, y2, r1, r2;
    while (T > 0)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        // 동일한 원일 경우
        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        // 안만나는 경우(안, 밖)
        else if (abs(r1 - r2) > l || (r1 + r2) < l)
        {
            cout << 0 << endl;
        }
        // 한점에서 만나는 경우(안, 밖)
        else if (abs(r1 - r2) == l || l == (r1 + r2))
        {
            cout << 1 << endl;
        }
        // 두 점에서 만나는 경우
        else if ((r1 + r2) > l)
            cout << 2 << endl;
        else
            cout << 0 << endl;
        T--;
    }
}