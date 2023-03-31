#include <iostream>
using namespace std;

int arr[50];
int N, num;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr[i] = num;
    }
}

int count_max()
{
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        int num = arr[i];
        int num_max = num + 5;
        for (int k = 0; k < N; k++)
        {
            if (arr[k] < num_max && arr[k] >= num)
            {
                count++;
            }
        }
        if (max < count)
            max = count;
    }
    return max;
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    init();
    int result = count_max();
    cout << 5 - result << endl;
}