#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> P;

void init()
{
    cin >> N;
    int p;
    for (int i = 0; i < N; i++)
    {
        cin >> p;
        P.push_back(p);
    }
}
int solution()
{
    sort(P.begin(), P.end());
    int sum = 0;
    int total = 0;
    for (int i = 0; i < P.size(); i++)
    {
        sum += P[i];
        total += sum;
    }
    return total;
}

int main()
{
    init();
    int result = solution();
    printf("%d\n", result);
}