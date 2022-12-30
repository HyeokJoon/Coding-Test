#include <iostream>
using namespace std;

int main()
{
    int N;
    int next = 1;
    cin >> N;
    while (1)
    {
        N -= next;
        if (N < 0)
            break;
        next++;
    }
    if (next % 2 == 0)
    {
        cout << 0;
    }
    else
    {
        cout << -N;
    }
}