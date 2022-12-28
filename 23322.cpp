#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    int a;
    cin >> N >> K;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    int count = 0;
    int max_eat = 0;
    while (1)
    {
        int max = 0;
        int max_i;
        for (int i = K; i < N; i++)
        {
            if (arr[i] - arr[i - K] > max)
            {
                max = arr[i] - arr[i - K];
                max_i = i;
            }
        }
        if (max == 0)
            break;
        arr[max_i] = arr[max_i - K];
        sort(arr.begin(), arr.end());
        count++;
        max_eat += max;
    }
}