#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq_right;
priority_queue<int, vector<int>, less<int>> pq_left;

int N;
int num, mid;
void solution()
{
    cin >> N;
    cin >> mid;
    printf("%d\n", mid);
    pq_left.push(mid);
    for (int i = 1; i < N; i++)
    {
        cin >> num;
        if (mid >= num)
        {
            pq_left.push(num);
            if (pq_left.size() > pq_right.size() + 1)
            {
                mid = pq_left.top();
                pq_right.push(mid);
                pq_left.pop();
            }
        }
        else
        {
            pq_right.push(num);
            if (pq_left.size() < pq_right.size())
            {
                mid = pq_right.top();
                pq_left.push(mid);
                pq_right.pop();
            }
        }

        printf("%d\n", pq_left.top());
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}