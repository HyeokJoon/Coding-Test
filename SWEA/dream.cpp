#include <iostream>
using namespace std;

int idx[10000001];
int arr[200001];
int max_r[200001];
int max_c[200001];
int safe[200001];
int T, N, M, Q;
int cnt, sum;

void init()
{
    scanf("%d %d %d", &N, &M, &Q);
    // cin >> N >> M >> Q;
    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &num);
            // cin >> num;
            int id = i * M + j;
            arr[id] = num;
            idx[num] = id;
            if (max_r[i] < num)
            {
                max_r[i] = num;
            }
            if (max_c[j] < num)
            {
                max_c[j] = num;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (max_r[i] == max_c[j])
            {
                safe[i * M + j] = 1;
                cnt++;
            }
        }
    }
}

void calc()
{
    int r, c, x;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d %d", &r, &c, &x);
        // cin >> r >> c >> x;
        r -= 1;
        c -= 1;
        int id = r * M + c;
        if (safe[id])
        {
            arr[id] = x;
            idx[x] = id;
        }
        else
        {
            if (safe[idx[max_c[c]]] && max_c[c] < x)
            {
                cnt--;
                safe[idx[max_c[c]]] = 0;
                max_c[c] = x;
            }
            else if (max_c[c] < x)
            {
                max_c[c] = x;
            }
            if (safe[idx[max_r[r]]] && max_r[r] < x)
            {
                cnt--;
                safe[idx[max_r[r]]] = 0;
                max_r[r] = x;
            }
            else if (max_r[r] < x)
            {
                max_r[r] = x;
            }
            if (max_r[r] == max_c[c])
            {
                safe[id] = 1;
                cnt++;
            }
            arr[id] = x;
            idx[x] = id;
        }
        sum += cnt;
    }
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i * M + j] = 0;
            safe[i * M + j] = 0;
            max_c[i * M + j] = 0;
            max_r[i * M + j] = 0;
            cnt = 0;
            sum = 0;
        }
    }
}

int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        init();
        calc();
        printf("#%d %d\n", i, sum);
        // cout << "#" << i << ' ' << sum << "\n";
        clear();
    }
    return 0;
}