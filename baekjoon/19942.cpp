#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, mp, mf, ms, mv;
int p, f, s, v, c, ret = 987654321, sum;
struct A
{
    int mp, mf, ms, mv, cost;
} a[16];
map<int, vector<vector<int>>> ret_v;

int main()
{
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }

    //전체 경우의수
    for (int i = 0; i < (1 << n); i++)
    {
        //들어가는 식재료 번호를 담을 벡터
        vector<int> vec;
        p = f = s = v = sum = 0;
        //각 식재료들
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                vec.push_back(j + 1);
                p += a[j].mp;
                f += a[j].mf;
                s += a[j].ms;
                v += a[j].mv;
                sum += a[j].cost;
            }
        }
        if (p >= mp && f >= mf && s >= ms && v >= mv)
        {
            if (ret >= sum)
            {
                ret = sum;
                ret_v[ret].push_back(vec);
            }
        }
    }
    if (ret == 987654321)
        cout << -1 << "\n";
    else
    {
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";
        for (int a : ret_v[ret][0])
        {
            cout << a << " ";
        }
    }
}