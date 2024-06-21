#include <iostream>
using namespace std;

int arr[1000001] = {0};

void makeisPrime(int num)
{
    arr[1] = 1;
    for (int i = 2; i <= num / 2; i++)
    {
        int n = i * 2;
        while (n <= num)
        {
            arr[n] = 1;
            n += i;
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    makeisPrime(b);

    for (int i = a; i <= b; i++)
    {
        if (arr[i] == 0)
            cout << i << "\n";
    }
}