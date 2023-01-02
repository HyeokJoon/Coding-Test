#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;
    int n, k;
    cin >> n >> k;
    int next = 1;
    int dec = next;
    S.push(0);
    int count = 0;
    while (count < 5)
    {
        for (int i = 1; i < k; i++)
        {
            if (S.empty())
            {
                while (dec)
                {
                    S.push(dec % 2);
                    dec = dec / 2;
                }
                next++;
                dec = next;
            }
            S.pop();
        }
        if (S.empty())
        {
            while (dec)
            {
                S.push(dec % 2);
                dec = dec / 2;
            }
            next++;
            dec = next;
        }
        k = n;
        cout << S.top();
        S.pop();
        count++;
    }
}