#include <iostream>
#include <algorithm>
using namespace std;

long long n, s, num;
long long dist, ret;

// 두 수의 최대공약수 찾기
int GCD(int a, int b)
{
    int maxi = max(a, b);
    int mini = min(a, b);
    while (mini != 0)
    {
        int tmp = mini;
        mini = maxi % mini;
        maxi = tmp;
    }
    return maxi;
}

void solution()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        dist = abs(num - s);
        ret = GCD(dist, ret);
    }
    cout << ret;
}

int main()
{
    solution();
}
