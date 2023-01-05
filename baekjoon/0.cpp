#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2)
{
    vector<int> answer;
    for (num1; num1 <= num2; num1++)
    {
        answer.push_back(numbers[num1]);
    }
    return answer;
}