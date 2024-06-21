#include <iostream>
#include <queue>
using namespace std;

int n, k, answer;
int arr[100010];
int cnt[100010];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void bfs()
{
    queue<int> q;
    q.push(n);
    arr[n] = 1;
    while (q.size())
    {

        int cur = q.front();
        q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2})
        {
            if (next > 100000 || next < 0)
                continue;

            if (!arr[next])
            {
                arr[next] = arr[cur] + 1;
                q.push(next);
                cnt[next] += cnt[cur];
            }

            if (arr[next] == arr[cur] + 1)
            {
                cnt[next]++;e
            }
            if (next == k)
            {
                answer = arr[k];
                return;
            }
        }
    }
    answer = arr[k];
}

int main()
{
    fastIO();
    cin >> n >> k;
    bfs();
    cout << answer - 1 << "\n"
         << cnt << "\n";
}