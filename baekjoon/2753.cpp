#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            arr[i][j] += a;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}