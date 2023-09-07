#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int Ns[1000001];
vector<int> arr;
void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Ns[i];
        arr.push_back(Ns[i]);
    }
    sort(arr.begin(), arr.end());                         // 정렬
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // 중복제거
}
int BinarySearch_min(int left, int right, int target)
{
    int mid;
    int _min;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            _min = mid;
            right = mid - 1;
        }
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return _min;
}

void solution()
{
    int target;
    for (int i = 0; i < N; i++)
    {
        target = Ns[i];
        printf("%d ", BinarySearch_min(0, arr.size() - 1, target));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solution();
}