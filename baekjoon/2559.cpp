#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> temp;

void init()
{
    cin >> N >> K;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        temp.push_back(a);
    }
}

void solution()
{
    int result = 0;
    int sIdx = 0;
    int eIdx = K;
    for (int i = 0; i < K; i++)
    {
        result += temp[i];
    }
    int maxi = result;

    while (eIdx != N)
    {
        result -= temp[sIdx];
        result += temp[eIdx];
        maxi = max(result, maxi);

        eIdx++;
        sIdx++;
    }
    cout << maxi;
}

int main()
{
    init();
    solution();
}