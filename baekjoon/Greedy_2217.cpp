#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;
vector<int> lope;

void init()
{
    cin >> N;
    int k;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        lope.push_back(k);
    }
}

int solution()
{
    sort(lope.begin(), lope.end(), greater<>());
    int l = lope[0];
    int cnt = 1;
    int w = l * cnt;
    for (int i = 1; i < N; i++)
    {
        cnt++;
        if (w < lope[i] * cnt)
        {
            w = lope[i] * cnt;
        }
    }
    return w;
}

int main()
{
    init();
    result = solution();
    printf("%d\n", result);
}