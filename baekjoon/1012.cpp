#include <iostream>
using namespace std;

class Node
{
public:
    int plant;
    Node *head;
};

Node point[52][52];
int T, N, M, K, result;

void init()
{
    result = 0;
    cin >> M >> N >> K;
    for (int m = 0; m < M + 2; m++)
    {
        for (int n = 0; n < N + 2; n++)
        {
            point[m][n].plant = 0;
            point[m][n].head = nullptr;
        }
    }
}

void check_head(Node *node1, Node *node2)
{
    if (node1->head == nullptr)
    {
        return;
    }
    while (node1->head != node1)
    {
        node1 = node1->head;
    }
    while (node2->head != node2)
    {
        node2 = node2->head;
    }
    if (node1->head != node2->head)
    {

        node2->head = node1;
        result--;
    }
}

void calc()
{
    int x, y;
    for (int k = 0; k < K; k++)
    {
        cin >> x >> y;
        x++;
        y++;
        point[x][y].plant = 1;
        point[x][y].head = &point[x][y];
        result++;
        check_head(&point[x - 1][y], &point[x][y]);
        check_head(&point[x + 1][y], &point[x][y]);
        check_head(&point[x][y - 1], &point[x][y]);
        check_head(&point[x][y + 1], &point[x][y]);
    }
}

int main()
{
    freopen("baekjoon/input.txt", "r", stdin);
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        init();
        calc();
        cout << result << endl;
    }
}