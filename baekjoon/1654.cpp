#include <iostream>
#include <math.h>
using namespace std;

long long k, n;
long long arr[10010];
long long answer;

void binarySearch(long long left, long long right)
{

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += arr[i] / mid;
        }

        if (sum >= n)
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;

    long long maxi = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    binarySearch(1, maxi);
    cout << answer;
}