#include <iostream>
using namespace std;

int count1 = 0;
int count2 = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        count1++;
        return 1;
    }
    else
        return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n)
{
    int *f;
    f[1] = -1;
    f[2] = -1;
    for (int i = 3; i < n + 1; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        count2++;
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    cout << fibonacci(n) << endl;
    cout << count1 << ' ' << count2;
}