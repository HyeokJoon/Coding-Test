#include <iostream>
using namespace std;

long long K, N;
long long arr[10001];
long long sum;
// O(k)
void init()
{
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
}
//
void binarySearch(long long left, long long right, long long target)
{
    long long _max = 0;
    long long mid;
    long long tot;
    while (left <= right)
    {

        mid = (left + right) / 2;
        tot = 0;
        for (int j = 0; j < K; j++)
        {
            tot += arr[j] / mid;
        }
        if (tot >= N)
        {
            if (_max < mid)
                _max = mid;
            left = mid + 1;
        }
        else if (tot < N)
        {
            right = mid - 1;
        }
    }
    printf("%lld", _max);
}

int main()
{
    init();
    binarySearch(1, sum / N, N);
}