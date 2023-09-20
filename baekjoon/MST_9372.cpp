#include <iostream>
using namespace std;

int N, M, T, s, e;
int cnt;

void init()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        init();
        printf("%d\n", N - 1);
    }
}