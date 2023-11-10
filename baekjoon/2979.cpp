#include <iostream>
using namespace std;

int A, B, C;
int pay[4];
int startT[101];
int endT[101];

int main()
{
    cin >> pay[1] >> pay[2] >> pay[3];
    int cnt = 0;
    int s, e;
    for (int i = 0; i < 3; i++)
    {
        cin >> s >> e;
        startT[s]++;
        endT[e]++;
    }
    int answer = 0;
    for (int i = 0; i < 101; i++)
    {
        if (startT[i] != 0)
        {
            cnt += startT[i];
        }
        if (endT[i] != 0)
        {
            cnt -= endT[i];
        }
        answer += cnt * pay[cnt];
    }
    cout << answer;
}