#include <iostream>
using namespace std;

int main()
{
    int K;
    cin >> K;
    int a[6];
    int b[6];
    int empty;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if ((a[i % 6] == a[(i + 2) % 6]) && (a[(i + 1) % 6] == a[(i + 3) % 6]))
        {
            empty = b[(i + 1) % 6] * b[(i + 2) % 6];
        }
    }
    int max_x = 0;
    int max_y = 0;
    for (int i = 0; i < 6; i++)
    {
        if ((a[i] == 1 || a[i] == 2))
        {
            if (max_x < b[i])
                max_x = b[i];
        }
        else
        {
            if (max_y < b[i])
                max_y = b[i];
        }
    }
    cout << (max_x * max_y - empty) * K << endl;
}