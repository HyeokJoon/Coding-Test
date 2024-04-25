#include <iostream>
using namespace std;

int a, b, c;
int arr[10];

int main()
{
    cin >> a;
    cin >> b;
    cin >> c;
    int ret = a * b * c;
    while (ret > 0)
    {
        arr[ret % 10]++;
        ret /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }
}