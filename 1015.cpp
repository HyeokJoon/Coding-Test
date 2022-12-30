#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, num;
    int idx = 0;
    cin >> N;
    vector<int> A(N);
    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        // A.push_back(num);
    }
    int count = 0;
    while (count < N)
    {
        int min = 1001;
        for (int i = 0; i < N; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
                idx = i;
            }
        }
        A[idx] = 1001;
        P[idx] = count;
        count++;
    }
    for (int i = 0; i < P.size(); i++)
    {
        cout << P[i] << ' ';
    }
}