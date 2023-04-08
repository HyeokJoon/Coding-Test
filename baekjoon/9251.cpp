#include <iostream>
using namespace std;

string A, B;
int sizeA, sizeB;
int lcs[1001][1001];

void init()
{
    cin >> A >> B;
    sizeA = A.length();
    sizeB = B.length();
}

int LCS()
{
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            if (A[i] == B[j])
            {
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            }
            else
            {
                lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
            }
        }
    }
    return lcs[sizeA][sizeB];
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    init();
    int result = LCS();
    printf("%d\n", result);
}