#include <iostream>
using namespace std;
int N;
int t[1500001];
int p[1500001];
int d[1500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 입력값
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i] >> p[i];
    }

    // 핵심
    for (int i = N; i >= 1; i--)
    {
        if (i + t[i] > N + 1) // 시간 상 할 수 없는 일이라면,
        {
            d[i] = d[i + 1]; // 다음날의 일을 하도록 함.
        }
        else
        {
            if (i + 1 > N) // i가 N일경우, 아래의 d[i+1]은 오류가 나므로 예외처리
            {
                d[i] = p[i] + d[i + t[i]];
                continue;
            }

            d[i] = max(d[i + 1], p[i] + d[i + t[i]]);
            // 다음날의 일과, 다음시간의 일을 더한 값 중 큰 값을 현재 값으로 둠.
        }
    }

    printf("%d\n", d[1]);
    return 0;
}