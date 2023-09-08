#include <iostream>
#include <queue>
using namespace std;
long long K, t;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void init()
{
    while (!pq.empty())
    {
        pq.pop();
    }
    cin >> K;
    int n;
    for (int i = 0; i < K; i++)
    {
        cin >> n;
        pq.push(n);
    }
}
long long solution()
{
    long long sum = 0;
    long long cur = 0;
    while (pq.size() > 1)
    {
        long long num1 = pq.top();
        pq.pop();
        long long num2 = pq.top();
        pq.pop();
        cur = num1 + num2;
        pq.push(cur);
        sum += cur;
    }
    return sum;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        init();
        printf("%lld\n", solution());
    }
}