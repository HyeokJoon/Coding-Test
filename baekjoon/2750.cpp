#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
}