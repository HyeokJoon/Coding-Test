#include <iostream>
#include <map>
using namespace std;

int K, L;
map<string, int> m;
string arr[500002];
string classNo;
void init()
{
    cin >> K >> L;
    for (int i = 1; i <= L; i++)
    {
        cin >> classNo;
        if (m.find(classNo) != m.end())
        {
            int idx = m[classNo];
            arr[idx] = "0";
        }
        m[classNo] = i;
        arr[i] = classNo;
    }
}
void solution()
{
    int cnt = 1;
    for (int i = 1; i <= L; i++)
    {
        if (cnt > K)
            break;
        if (arr[i] == "0")
            continue;
        cout << arr[i] << "\n";
        cnt++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solution();
}