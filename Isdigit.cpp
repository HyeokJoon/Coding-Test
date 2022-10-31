#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0;
    for (const auto v : my_string)
    {
        if (isdigit(v))
        {
            answer += v - '0';
        }
    }
    return answer;
}
