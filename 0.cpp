#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            if (n % i == 0)
            {
                n /= i;
                i--;
            }
            else
            {
                break;
            }
        }
    }
    if (n == 1)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    return answer;
}