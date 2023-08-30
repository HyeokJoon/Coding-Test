/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
*/

#include <iostream>
using namespace std;
int N;
int arr[1001];
int lis[1001];

int binarySearch(int left, int right, int target)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (lis[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right;
}

int main()
{
    //초기화
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int j = 0;
    lis[j] = arr[0];
    // 모든 element비교

    for (int i = 1; i < N; i++)
    {
        if (lis[j] < arr[i])
        {
            lis[++j] = arr[i];
        }
        else
        {
            int idx = binarySearch(0, j, arr[i]);
            lis[idx] = arr[i];
        }
    }
    printf("%d\n", j + 1);
}