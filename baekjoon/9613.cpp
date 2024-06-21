#include <iostream>
using namespace std;

int t, n;
int arr[101];

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int GCD(int a, int b)
{
    int mini, maxi;
    if (a > b)
    {
        mini = b;
        maxi = a;
    }
    else
    {
        mini = a;
        maxi = b;
    }

    if (maxi != 0 && mini == 0)
        return maxi;

    return GCD(mini, maxi % mini);
}

void solution()
{
    init();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += GCD(arr[i], arr[j]);
        }
    }
    cout << sum << "\n";
}

int main()
{
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        solution();
    }
}