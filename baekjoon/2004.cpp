#include <iostream>
using namespace std;

int calc(int num1, int num2)
{
    for(int i=1; i<num1; i++){
        
    }
}

int calc_ten(int n)
{
    // n의 2의 개수와 5의 개수

    int cnt2 = 0;
    int cnt5 = 0;
    while (n % 2 == 0)
    {
        cnt2 += 1;
        n /= 2;
    }
    while (n % 5 == 0)
    {
        cnt5 += 1;
        n /= 5;
    }
    return min(cnt2, cnt5);
}

int combi(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return combi(n - 1, r - 1) + combi(n - 1, r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ret = combi(n, m);
    int result = calc_ten(ret);
    cout << result;
}