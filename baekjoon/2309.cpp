#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[9];
vector<int> selected;
int flag;

void combi(int start, vector<int> b, int sum)
{
    if (flag)
        return;
    if (b.size() == 7 && sum == 100)
    {
        sort(b.begin(), b.end());
        flag = 1;
        for (int a : b)
            cout << a << "\n";
    }
    else
    {
        for (int i = start + 1; i < 9; i++)
        {
            b.push_back(arr[i]);
            combi(i, b, sum + arr[i]);
            b.pop_back();
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    combi(-1, selected, 0);
}
