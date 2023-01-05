#include <iostream>
#include <string.h>
using namespace std;

int cnt = 0;
int recursion(const char *s, int l, int r)
{
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1);
}
int main()
{
    int T;
    char a[1001];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cnt = 0;
        cin >> a;
        cout << isPalindrome(a) << ' ' << cnt << endl;
    }
}