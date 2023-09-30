#include <iostream>
using namespace std;

int N;
int main()
{
    cin >> N;
    if (N % 4 == 0)
    {
        printf("%s\n", "CY");
    }
    else if (N % 4 == 1)
    {
        printf("%s\n", "SK");
    }
    else if (N % 4 == 2)
    {
        printf("%s\n", "CY");
    }
    else
    {
        printf("%s\n", "SK");
    }
}