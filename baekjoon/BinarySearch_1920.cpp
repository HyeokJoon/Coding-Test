#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Ns[100001];
int Ms[100001];
void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Ns[i];
    }
    cin >> M;
    for (int j = 0; j < M; j++)
    {
        cin >> Ms[j];
    }
    sort(Ns, Ns + N);
}

int BinarySearch(int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Ns[mid] == target)
        {
            return 1;
        }
        if (Ns[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

void solution()
{
    int result;
    for (int i = 0; i < M; i++)
    {
        int target = Ms[i];
        result = BinarySearch(0, N - 1, target);
        printf("%d\n", result);
    }
}

int main()
{
    init();
    solution();
}