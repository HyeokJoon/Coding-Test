#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>());

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (A[i] * B[i]);
    }
    printf("%d\n", sum);
}