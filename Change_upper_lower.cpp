#include <string>
#include <vector>

using namespace std;

string solution(string my_string)
{
    for (auto &v : my_string)
    {
        if (islower(v))
        {
            v = toupper(v);
        }
        else
        {
            v = tolower(v);
        }
    }
    return my_string;
}