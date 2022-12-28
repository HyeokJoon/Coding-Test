#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < a[0].length(); i++)
    {
        if (a[2][i] == 'm')
        {
            a[0][i] = 'o';
            a[1][i] = 'w';
            a[2][i] = 'l';
            a[3][i] = 'n';
            a[4][i] = '.';
        }
        if (a[2][i] == 'l')
        {
            a[0][i] = '.';
            a[1][i] = 'o';
            a[2][i] = 'm';
            a[3][i] = 'l';
            a[4][i] = 'n';
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i];
    }
}