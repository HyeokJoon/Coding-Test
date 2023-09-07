#include <iostream>
#include <queue>
using namespace std;

class cmp
{
public:
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b)) // 절대값이 같으면 a와 b 중 큰 값으로
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int N;
int oper[100001];
priority_queue<int, vector<int>, cmp> pq;
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
    int op;
    for (int i = 0; i < N; i++)
    {
        op = oper[i];
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