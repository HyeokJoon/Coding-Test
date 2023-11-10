#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int N, K, cnt;
int robots[201];
int flag;
queue<int> robot;
deque<int> A;

void moveBelt()
{
    int last = A.back();
    A.pop_back();
    A.push_front(last);
    int num = robot.size();
    int idx = 0;
    for (int i = 0; i < num; i++)
    {
        idx = robot.front();
        robot.pop();
        robots[idx] = 0;
        if (idx + 1 == N)
            continue;
        robot.push(idx + 1);
        robots[idx + 1] = 1;
    }
}
void moveRobot()
{
    int num = robot.size();
    int idx = 0;
    for (int i = 0; i < num; i++)
    {
        idx = robot.front();
        robot.pop();
        robots[idx] = 0;
        if (A[idx + 1] > 0 && robots[idx + 1] == 0)
        {
            A[idx + 1]--;
            if (A[idx + 1] == 0)
                cnt++;
            if (idx + 1 != N)
            {
                robot.push(idx + 1);
                robots[idx + 1] = 1;
            }
        }
        else
        {
            robot.push(idx);
            robots[idx] = 1;
        }
    }
}
void setRobot()
{
    if (A[0] > 0)
    {
        robot.push(0);
        robots[0] = 1;
        A[0]--;
        if (A[0] == 0)
            cnt++;
    }
}
void check()
{
    if (cnt >= K)
        flag = 1;
}
int solution()
{
    int count = 0;
    while (flag == 0)
    {
        count++;
        moveBelt();
        moveRobot();
        setRobot();
        check();
        printf("count : %d\n", count);
        printf("robot : %d %d %d %d \n", robots[0], robots[1], robots[2], robots[3]);
        printf("belt : %d %d %d %d %d %d %d %d\n\n", A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7]);
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    int a;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> a;
        A.push_back(a);
        if (a == 0)
            cnt++;
    }
    printf("%d\n", solution());
}