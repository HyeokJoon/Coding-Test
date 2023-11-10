#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string input, string delimeter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.size());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    string s = "가나다라 마마마마마";
    string d = " ";
    // cin >> s;
    vector<string> a = split(s, d);
    for (string b : a)
        cout << b << "\n";
}