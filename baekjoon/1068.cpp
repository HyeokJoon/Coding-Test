#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, leaf;
set<int> leafNode;
int child[50];
int parent[50];
int p_c[50][50];

void init()
{
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++)
    {
        leafNode.insert(i);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        p_c[n][i] = 1;
        parent[i] = n;
        // child[n]++;
        leafNode.erase(n);
    }
}
void calc()
{
    int delNum, num;
    scanf("%d", &delNum);
    queue<int> s;
    s.push(delNum);
    while (!s.empty())
    {
        num = s.front();
        s.pop();
        for (int i = 0; i < N; i++)
        {
            if (p_c[num][i] == 1)
            {
                s.push(p_c[num][i]);
                p_c[num][i] = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (parent[i] == num)
            {
                s.push(i);
                parent[i] = -1;
                leafNode.erase(i);
                child[parent[num]]--;
            }
        }
    }
    if (!child[parent[delNum]])
    {
        leafNode.insert(parent[delNum]);
    }
    leaf = leafNode.size();
}
int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    init();
    calc();
    printf("%d\n", leaf);
}