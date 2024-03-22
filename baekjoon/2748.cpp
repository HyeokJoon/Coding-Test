#include <iostream>
using namespace std;

typedef long long ll;

ll dp[91], n;
ll fibo(ll idx)
{
    if (idx == 0 || idx == 1)
        return idx;
    ll &ret = dp[idx];
    if (ret)
        return ret;
    return ret = fibo(idx - 1) + fibo(idx - 2);
}

int main()
{
    cin >> n;
    cout << fibo(n);
}