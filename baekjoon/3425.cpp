#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX_NUM 1000000000

queue<string> opArr;
queue<long long> numArr;
queue<long long> addNum;
string op;
long long N = 1;
long long num;
stack<long long> goStack;

void init()
{
    while (!addNum.empty())
    {
        addNum.pop();
    }
    while (!opArr.empty())
    {
        opArr.pop();
    }
    while (op != "END")
    {
        if (op == "NUM")
        {
            scanf("%d", &num);
            addNum.push(num);
        }
        opArr.push(op);
        cin >> op;
    }
    opArr.push(op);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        numArr.push(num);
    }
}

void print()
{
    if (goStack.size() != 1)
    {
        printf("ERROR\n");
        return;
    }
    long long result = goStack.top();
    goStack.pop();
    printf("%d\n", result);
};
void error()
{
    string oper;
    do
    {
        oper = opArr.front();
        opArr.pop();
        opArr.push(oper);
    } while (oper != "END");
    printf("ERROR\n");
}
bool run()
{
    while (!goStack.empty())
    {
        goStack.pop();
    }
    long long x, y;
    goStack.push(numArr.front());
    numArr.pop();
    while (1)
    {
        string oper = opArr.front();
        opArr.pop();
        opArr.push(oper);
        if (oper == "END")
            break;
        if (oper == "NUM")
        {
            x = addNum.front();
            addNum.pop();
            addNum.push(x);
            goStack.push(x);
        }
        else if (oper == "POP")
        {
            if (goStack.empty())
            {
                error();
                return false;
            }
            goStack.pop();
        }
        else if (oper == "INV")
        {
            if (goStack.empty())
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.pop();
            goStack.push(0 - x);
        }
        else if (oper == "DUP")
        {
            if (goStack.empty())
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.push(x);
        }
        else if (oper == "SWP")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            goStack.push(x);
            goStack.push(y);
        }
        else if (oper == "ADD")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            if (abs(y + x) > MAX_NUM)
            {
                error();
                return false;
            }
            goStack.push(y + x);
        }
        else if (oper == "SUB")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            if (abs(y - x) > MAX_NUM)
            {
                error();
                return false;
            }
            goStack.push(y - x);
        }
        else if (oper == "MUL")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            if (abs(y * x) > MAX_NUM)
            {
                error();
                return false;
            }
            goStack.push(y * x);
        }
        else if (oper == "DIV")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            if (x == 0)
            {
                error();
                return false;
            }
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            goStack.push(y / x);
        }
        else if (oper == "MOD")
        {
            if (goStack.size() < 2)
            {
                error();
                return false;
            }
            x = goStack.top();
            if (x == 0)
            {
                error();
                return false;
            }
            goStack.pop();
            y = goStack.top();
            goStack.pop();
            goStack.push((abs(y) % abs(x)) * (abs(y) / y));
        }
    }
    return true;
}

int main()
{

    freopen("baekjoon/input.txt", "r", stdin);
    while (1)
    {
        cin >> op;

        if (op == "QUIT")
        {
            break;
        }

        init();

        for (int i = 0; i < N; i++)
        {
            if (run())
            {
                print();
            }
        }
        printf("\n");
    }
}