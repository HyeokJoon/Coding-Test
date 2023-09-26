#include <iostream>
#include <deque>
using namespace std;

int N, mcount;
int map[21][21];
deque<int> ROW[21];
deque<int> COL[21];
int result;
void solution(deque<int> *row, deque<int> *col, int x);

void init()
{
    cin >> N;
    int m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> m;
            if (m)
            {
                ROW[i].push_back(m);
                COL[j].push_back(m);
            }
        }
    }
}

void moveL(deque<int> Grow[21], int x)
{
    deque<int> row[21];
    deque<int> col[21];
    for (int i = 0; i < N; i++)
    {
        row[i] = Grow[i];
    }
    int n1, n2;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        int j = 0;
        int k = row[i].size();
        if (k == 0)
            continue;
        while (cnt < k)
        {
            n1 = row[i].front();
            row[i].pop_front();
            cnt++;
            if (cnt == k)
            {
                if (n1 > result)
                    result = n1;
                row[i].push_back(n1);
                col[j++].push_back(n1);
                break;
            }
            n2 = row[i].front();
            row[i].pop_front();
            cnt++;
            if (n1 == n2)
            {
                int n3 = n1 + n2;
                if (n3 > result)
                    result = n3;
                row[i].push_back(n3);
                col[j++].push_back(n3);
            }
            else
            {
                row[i].push_back(n1);
                col[j++].push_back(n1);
                if (cnt == k)
                {
                    row[i].push_back(n2);
                    col[j++].push_back(n2);
                    break;
                }
                row[i].push_front(n2);
                cnt--;
            }
        }
    }
    solution(row, col, ++x);
}

void moveR(deque<int> Grow[21], int x)
{
    deque<int> row[21];
    deque<int> col[21];
    for (int i = 0; i < N; i++)
    {
        row[i] = Grow[i];
    }
    int n1, n2;
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        int cnt = 0;
        int k = row[i].size();
        if (k == 0)
            continue;
        while (cnt < k)
        {
            n1 = row[i].back();
            row[i].pop_back();
            cnt++;
            if (cnt == k)
            {
                if (n1 > result)
                    result = n1;
                row[i].push_front(n1);
                col[j++].push_front(n1);
                break;
            }
            n2 = row[i].back();
            row[i].pop_back();
            cnt++;
            if (n1 == n2)
            {
                int n3 = n1 + n2;
                if (n3 > result)
                    result = n3;
                row[i].push_front(n3);
                col[j++].push_front(n3);
            }
            else
            {
                row[i].push_front(n1);
                col[j++].push_front(n1);
                if (cnt == k)
                {
                    row[i].push_front(n2);
                    col[j++].push_front(n2);
                    break;
                }
                row[i].push_back(n2);
                cnt--;
            }
        }
    }
    solution(row, col, ++x);
}
void moveU(deque<int> Gcol[21], int x)
{
    deque<int> row[21];
    deque<int> col[21];
    for (int i = 0; i < N; i++)
    {
        col[i] = Gcol[i];
    }
    int n1, n2;
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        int cnt = 0;
        int k = col[i].size();
        if (k == 0)
            continue;
        while (cnt < k)
        {
            n1 = col[i].front();
            col[i].pop_front();
            cnt++;
            if (cnt == k)
            {
                if (n1 > result)
                    result = n1;
                col[i].push_back(n1);
                row[j++].push_back(n1);
                break;
            }
            n2 = col[i].front();
            col[i].pop_front();
            cnt++;
            if (n1 == n2)
            {
                int n3 = n1 + n2;
                if (n3 > result)
                    result = n3;
                col[i].push_back(n3);
                row[j++].push_back(n3);
            }
            else
            {

                col[i].push_back(n1);
                row[j++].push_back(n1);
                if (cnt == k)
                {
                    col[i].push_back(n2);
                    row[j++].push_back(n2);
                    break;
                }
                col[i].push_front(n2);
                cnt--;
            }
        }
    }
    solution(row, col, ++x);
}
void moveD(deque<int> Gcol[21], int x)
{
    deque<int> row[21];
    deque<int> col[21];
    for (int i = 0; i < N; i++)
    {
        col[i] = Gcol[i];
    }
    int n1, n2;
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        int cnt = 0;
        int k = col[i].size();
        if (k == 0)
            continue;
        while (cnt < k)
        {
            n1 = col[i].back();
            col[i].pop_back();
            cnt++;
            if (cnt == k)
            {
                if (n1 > result)
                    result = n1;
                col[i].push_front(n1);
                row[j++].push_front(n1);
                break;
            }
            n2 = col[i].back();
            col[i].pop_back();
            cnt++;
            if (n1 == n2)
            {
                int n3 = n1 + n2;
                if (n3 > result)
                    result = n3;
                col[i].push_front(n3);
                row[j++].push_front(n3);
            }
            else
            {
                col[i].push_front(n1);
                row[j++].push_front(n1);
                if (cnt == k)
                {
                    col[i].push_front(n2);
                    row[j++].push_front(n2);
                    break;
                }
                col[i].push_back(n2);
                cnt--;
            }
        }
    }
    solution(row, col, ++x);
}
void solution(deque<int> *row, deque<int> *col, int x)
{
    if (x == 5)
    {
        return;
    }
    moveL(row, x);
    moveR(row, x);
    moveU(col, x);
    moveD(col, x);
}

int main()
{
    init();
    solution(ROW, COL, 0);
    printf("%d\n", result);
}