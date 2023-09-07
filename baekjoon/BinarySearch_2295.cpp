#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<int> sums;

void init()
{
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sums.push_back(arr[i] + arr[j]);
        }
    }
    sort(sums.begin(), sums.end());
    sums.erase(unique(sums.begin(), sums.end()), sums.end());
}

bool binarySearch(int left, int right, int target)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (sums[mid] == target)
            return true;
        else if (sums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

void solution()
{
    int target;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            target = arr[i] - arr[j];
            if (binarySearch(0, sums.size(), target))
            {
                printf("%d\n", arr[i]);
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solution();
}