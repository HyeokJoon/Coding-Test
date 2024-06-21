#include <iostream>
using namespace std;

int N;
int pay[1010][2];
int dic[1010];

int solution(int cur)
{
    if (dic[cur])
        return dic[cur];

    if (cur > N)
        return 0;
        
    int _max = 0, sum = 0;
    
    int t, p;
    for (int i = cur; i <= N; i++)
    {
        t = pay[i][0];
        p = pay[i][1];
        if (t + i > N + 1)
        {
            dic[i] = 0;
            continue;
        }
        sum = p + solution(i + t);
        if (sum > _max)
            _max = sum;
        sum = 0;
    }

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
    cout << result <<"\n";
}