#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int j = n;
    int answer = 0;
    for (j; j <= 0; j = j / 10)
    {
        answer += (j % 10);
    }
    return answer;
}
int main()
{
    cout << solution(122);
}