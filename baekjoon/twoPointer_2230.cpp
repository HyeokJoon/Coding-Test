#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long arr[100001];
void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}
long long s, e, dif;
long long mins = 2000000001;
void solution()
{
    sort(arr, arr + N);
    while (s < N && e < N)
    {
        dif = arr[e] - arr[s];
        if (dif < M)
        {
            e++;
        }
        else
        {
            if (dif < mins)
                mins = dif;
            s++;
        }
    }
}
int main()
{
    init();
    solution();
    printf("%lld\n", mins);
}