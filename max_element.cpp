#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> answer;
    auto t = max_element(array.begin(), array.end());
    answer.push_back(*t);
    answer.push_back(distance(array.begin(), t));
    return answer;
}