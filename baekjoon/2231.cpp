#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int c = n % 10;
    int comp = n / 10;
    int size = 1;
    int sum = 0;
    for (int i = comp; i > 0; i /= 10)
    {
        size++;
    }
    int tmp;
    int maxt = size * 10;

    int result = 0;
    for (;;)
    {
        sum = 0;
        for (int j = comp; j > 0; j /= 10)
        {
            sum += j % 10;
        }

        tmp = c - sum;
        if (tmp < 0)
        {
            c += 10;
            comp -= 1;
            continue;
        }
        if (tmp > maxt)
        {
            break;
        }
        else if (tmp % 2 == 1)
        {
            c += 10;
            comp -= 1;
            continue;
        }
        else
        {
            if ((tmp / 2) < 10)
            {
                result = (10 * comp) + (tmp / 2);
            }
        }
        c += 10;
        comp -= 1;
    }
    cout << result;
}