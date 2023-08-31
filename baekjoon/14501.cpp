#include <iostream>
using namespace std;

int N;
int pay[16][2];
int visited[16];
int dic[16];

int solution(int cur)
{
    if (visited[cur])
    {
        return dic[cur];
    }

    int _max = 0, sum = 0;
    if (cur > N)
    {
        return 0;
    }
    int t, p;
    for (int i = cur; i <= N; i++)
    {
        t = pay[i][0];
        p = pay[i][1];
        if (pay[i][0] + i > N + 1)
        {
            visited[i] = 1;
            dic[i] = 0;
            continue;
        }
        sum = p + solution(i + t);
        if (sum > _max)
            _max = sum;
        sum = 0;
    }
    visited[cur] = 1;
    dic[cur] = _max;
    return _max;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> pay[i][0] >> pay[i][1];
    }
    int result = solution(1);
    printf("%d\n", result);
}