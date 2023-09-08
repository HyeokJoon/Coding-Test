#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> pq;

void init()
{
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        pq.push(n);
    }
}
int solution()
{
    int sum = 0;
    int cur = 0;
    while (pq.size() > 1)
    {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        cur = num1 + num2;
        pq.push(cur);
        sum += cur;
    }
    return sum;
}

int main()
{
    init();
    printf("%d", solution());
}