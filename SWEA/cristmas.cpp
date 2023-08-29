#include <iostream>
#include <bitset>
using namespace std;

class Switch
{
public:
    int link;
    int value;
};

int N, M, K;
int arr = 0;
Switch switches[19];
int t, cnt;
int selected = 1;

void init()
{
    int num;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        if (num)
        {
            arr |= (1 << i);
        }
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> num;
            switches[i].link |= (1 << num);
        }
    }
}

void selectSwitch()
{
    for (int i = 1; i <= M; i++)
    {
        switches[i].value = arr & switches[i].link;
        switches[i].value = bitset<32>(switches[i].value).count();
    }
    for (int i = 1; i <= M; i++)
    {
        if (switches[selected].value > switches[i].value)
        {
            selected = i;
        }
    }
}

void switchOn()
{
    arr = arr ^ switches[selected].link;
    cnt++;
}

void printResult()
{
    cout << "#" << t << ' ' << cnt << "\n";
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        init();
        int s = 0;
        s |= (1 << N + 1) - 2;
        while (arr != s)
        {
            selectSwitch();
            switchOn();
        }
        printResult();
    }
}