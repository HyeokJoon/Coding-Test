#include <iostream>
#include <map>
using namespace std;

int N, M;
string arr[100001];
string questions[100001];
map<string, int> m;

void init()
{
    string name;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        arr[i] = name;
        m[name] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> questions[i];
    }
}
void solution()
{
    string q;
    for (int i = 0; i < M; i++)
    {
        q = questions[i];
        if (q[0] >= '0' && q[0] <= '9')
        {
            int num = stoi(q);
            // printf("%s\n", arr[num]);
            cout << arr[num] << "\n";
        }
        else
        {
            // printf("%d\n", m[q]);
            cout << m[q] << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solution();
}