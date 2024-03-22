#include <iostream>
using namespace std;

int N, M, L, R;
int a[100001];

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        R += a[i];
    }
    L = R / M;
}

bool check(int mid, int l, int r)
{
    int idx = 0;
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        while (sum + a[idx] <= mid)
        {
            if (idx >= N)
            {
                return true;
            }
            sum += a[idx++];
        }
    }
    return idx >= N;
}

void binarySearch(int l, int r)
{
    int ret = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, l, r))
        {
            ret = mid;
            r = mid - 1;
        }

        else
            l = mid + 1;
    }
    cout << ret;
}

int main()
{
    init();
    binarySearch(L, R);
}