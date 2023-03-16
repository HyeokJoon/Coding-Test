#include <iostream>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000

int value[MAX_N];
int segtree[2 * MAX_N]; // 1 ~ 2N-1 사용

int T, N, M;
int main()
{
    freopen("SWEA/input.txt", "r", stdin);
    scanf("%d", &T);
    scanf("%d %d", &N, &M);
}

void init()
{
    for (int i = 1; i < N; i++)
    {
        segtree[i + N] = value[i];
    }
    for (int i = N - 1; i != 0; --i)
    {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
/**
 * @brief
 * 원소 하나(리프 노드)가 바뀌면 원소를 포함하는 모든 구간(리프 노드의 모든 조상)의 값도 바뀌어야 한다.
 * @param i i번째 값
 * @param x x로 바꿈
 */
void update(int i, int x)
{
    segtree[i += N] = x;
    while (i >>= 1)
    {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}
