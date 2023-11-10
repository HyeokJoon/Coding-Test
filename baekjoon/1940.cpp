#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void init()
{
    cin >> N >> M;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
}

void solution()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] + arr[j]) == M)
                cnt++;
        }
    }
    printf("%d", cnt);
}

int main()
{
    init();
    solution();
}