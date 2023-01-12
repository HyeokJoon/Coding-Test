#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string *a = new string[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a->begin(), a->end());
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << endl;
    }
    delete[] a;
}