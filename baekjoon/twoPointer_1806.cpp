#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
long long result = __LONG_LONG_MAX__;
int arr[100001];

void init()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}
void solution()
{
    // sort(arr, arr + N);
    int s = 0, e = 0;
    int sum = 0;
    while (s <= e && e <= N)
    {
        if (sum >= S)
        {
            int len = e - s;
            if (len < result)
                result = len;
            sum -= arr[s++];
        }
        else
        {
            sum += arr[e++];
        }
    }
    if (result == __LONG_LONG_MAX__)
        result = 0;
}

int main()
{
    init();
    solution();
    printf("%lld\n", result);
}