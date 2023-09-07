#include <iostream>
#include <queue>
using namespace std;

int N;
int oper[100001];
priority_queue<int> pq;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> oper[i];
    }
}
void solution()
{
    for (int i = 0; i < N; i++)
    {
        int op = oper[i];
        if (op == 0)
        {
            if (pq.empty())
            {
                printf("%d\n", 0);
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(op);
        }
    }
}
int main()
{
    init();
    solution();
}