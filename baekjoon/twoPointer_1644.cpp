#include <iostream>
#include <vector>
using namespace std;

int N, cnt;
int v[4000001];
int vcount;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i)
            continue;
        else
            return false;
    }
    return true;
}

void init()
{
    cin >> N;
    // vector<bool> Prime(N + 1, true);
    // Prime[0] = false;
    // Prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime(i))
            v[vcount++] = i;
    }
}

void solution()
{
    int s = 0, e = 0;
    int sum = 0;
    while (s <= e && e <= N)
    {
        if (sum < N)
        {
            sum += v[e++];
        }
        else
        {
            if (sum == N)
                cnt++;
            sum -= v[s++];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
    printf("%d\n", cnt);
}
