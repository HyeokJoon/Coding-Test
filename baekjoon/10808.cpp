#include <iostream>
#include <vector>
using namespace std;

int arr[30];

int main()
{
    string s;
    cin >> s;
    char a;
    for (int i = 0; i < s.size(); i++)
    {
        a = s[i];
        arr[a - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << ' ';
    }
}