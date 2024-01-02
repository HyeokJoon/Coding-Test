#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void init(vector<string> &friends, vector<string> &gifts)
{
    // tc1
    //  friends = {"muzi", "ryan", "frodo", "neo"};
    //  gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};
    // tc2
    // friends = {"joy", "brad", "alessandro", "conan", "david"};
    // gifts = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"};
    // tc3
    friends = {"a", "b", "c"};
    gifts = {"a b", "b a", "c a", "a c", "a c", "c a"};
}

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

void solution(vector<string> &friends, vector<string> &gifts)
{
    map<string, int> m;
    map<string, int> ret;
    vector<string> vs;
    for (string s : gifts)
    {
        m[s]++;
        vs = split(s, " ");
        //주면 + 받으면 -
        m[vs[0]]++;
        m[vs[1]]--;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 두명 뽑아서 선물 횟수 비교
            string a = friends[i];
            string b = friends[j];
            string atob = a + " " + b;
            string btoa = b + " " + a;
            if (m[atob] > m[btoa])
                ret[a]++;
            else if (m[atob] < m[btoa])
                ret[b]++;
            else
            {
                // 선물 지수 비교
                if (m[a] > m[b])
                    ret[a]++;
                else if (m[a] < m[b])
                    ret[b]++;
            }
        }
    }
    int maxx = 0;
    string f;
    for (int i = 0; i < friends.size(); i++)
    {
        if (maxx < ret[friends[i]])
        {
            maxx = ret[friends[i]];
            f = friends[i];
        }
    }
    cout << maxx << endl;
}

int main()
{
    vector<string> friends;
    vector<string> gifts;
    init(friends, gifts);
    // cout << friends.size() << ' ' << gifts.size() << endl;

    solution(friends, gifts);
}