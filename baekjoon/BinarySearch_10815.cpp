#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Ns[500001];

void BinarySearch(int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Ns[mid] == target)
        {
            printf("%d ", 1);
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