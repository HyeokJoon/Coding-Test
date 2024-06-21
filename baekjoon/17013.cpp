#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int t, n;
bool arr[1000001];

void makeisPrime(int num)
{
    arr[1] = 1;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (arr[i] == 1)
            continue; // 이미 지워진 수 건너뛰기

        int n = i * i;
        while (n <= num)
        {
            arr[n] = 1;
            n += i;
        }
    }
}

void solution(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (arr[i] || arr[n - i])
        {
            continue;
        }
        cnt++;
    }
    cout << cnt << "\n";
}

int main()
{
    cin >> t;
    arr[0] = 1;
    arr[1] = 1;
    makeisPrime(1000000);
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        solution(n);
    }
}