#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int Ns[500001];
int findMax(int left, int right, int target)
{
    int _max;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Ns[mid] == target)
        {
            _max = mid;
            left = mid + 1;
        }
        else if (Ns[mid] > target)
        {
            right = mid - 1;
        }
        else if (Ns[mid] < target)
        {
            left = mid + 1;
        }
    }
    return _max;
}
int findMin(int left, int right, int target)
{
    int _min;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Ns[mid] == target)
        {
            _min = mid;
            right = mid - 1;
        }
        else if (Ns[mid] > target)
        {
            right = mid - 1;
        }
        else if (Ns[mid] < target)
        {
            left = mid + 1;
        }
    }
    return _min;
}
void BinarySearch(int left, int right, int target)
{
    int maxi = 0;
    int mini = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Ns[mid] == target)
        {
            maxi = findMax(mid, right, target);
            mini = findMin(left, mid, target);
            printf("%d ", maxi - mini + 1);
            return;
        }
        else if (Ns[mid] > target)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    printf("%d ", 0);
}

void solution()
{
    cin >> N;
    int key;
    int value;
    for (int i = 0; i < N; i++)
    {
        cin >> Ns[i];
    }
    sort(Ns, Ns + N);

    cin >> M;
    int target;
    for (int i = 0; i < M; i++)
    {
        cin >> target;
        BinarySearch(0, N - 1, target);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}