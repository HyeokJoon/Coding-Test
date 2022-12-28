#include <iostream>
using namespace std;

int main()
{
    int max_row, max_col;
    int max_num = -1;
    int num[9][9];

    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            cin >> num[j][i];
            if (max_num < num[j][i])
            {
                max_num = num[j][i];
                max_col = i + 1;
                max_row = j + 1;
            }
        }
    }
    cout << max_num << endl;
    cout << max_row << ' ' << max_col << endl;
}