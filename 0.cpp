#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2)
{
    int answer = 0;
    for (const auto v : s1)
    {
        for (const auto v2 : s2)
        {
            if (v == v2)
            {
                answer++;
            }
        }
    }
    return answer;
}
