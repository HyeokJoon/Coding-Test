#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void init(vector<vector<int>> &dice)
{
    dice = {{1, 2, 3, 4, 5, 6}, {3, 3, 3, 3, 4, 4}, {1, 3, 3, 4, 4, 4}, {1, 1, 4, 4, 5, 5}};
}

void solution(vector<vector<int>> &dice)
{
    map<int, vector<int>> m;
    map<int, int> p;
    vector<int> idx;

    for (int i = 0; i < dice.size(); i++)
    {
        idx.push_back(i + 1);
        m[i + 1] = dice[i];
        for (int j = 0; j < dice[0].size(); j++)
        {
            p[dice[i][j]]++;
        }
    }
    sort(dice.begin(), dice.end());
    cout << "start Permutation" << endl;
    do
    {
        for (int i = 0; i < dice.size(); i++)
        {
            for (int j = 0; j < dice[0].size(); j++)
            {
                cout << dice[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < dice.size() / 2; i++)
        {
            for (int j = 0; j < dice[0].size(); j++)
            {
            }
        }

    } while (next_permutation(dice.begin(), dice.end()));
}

int main()
{
    vector<vector<int>> dice;
    init(dice);
    solution(dice);
}