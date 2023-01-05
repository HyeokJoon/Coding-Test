#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a;
    int A[N + 1];
    int mul = 1;
    for (int i = 0; i < N + 1; i++)
    {
        A[i] = 0;
    }
    for (int i = 1; i < N + 1; i++)
    {
        cin >> a;
        A[a]++;
    }
    for (int i = 1; i < N + 1; i++)
    {
        if (A[i] != 0)
        {
            mul *= (A[i] + 1);
        }
    }
    cout << (mul - 1) % 1000000007;
}