#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr;
    vector<int> count;
    //산술평균
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        sum += a;
    }
    int avg = round(sum / N);
    cout << avg << endl;
    //중앙값
    sort(arr.begin(), arr.end());
    cout << arr[(N / 2)] << endl;
    //최빈값
    int freq[4000] = {0};
    vector<int> f;
    int maxf = 0;
    for (int i = 0; i < N; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0; i < 4000; i++)
    {
        if (maxf < freq[i])
        {
            maxf = freq[i];
        }
    }
    for (int i = 0; i < 4000; i++)
    {
        if (freq[i] == maxf)
            f.push_back(i);
    }
    sort(f.begin(), f.end());
    for (auto a : f)
    {
        cout << f[a];
    }
    if (f.size() == 1)
        cout << f[0] << endl;
    else
        cout << f[1] << endl;
    // 범위
    cout << abs(arr.front() - arr.back()) << endl;
}