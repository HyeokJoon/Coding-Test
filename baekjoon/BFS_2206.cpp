#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int x;
    int y;
    int flag;
    int dist;
};

int N, M;
int map[1002][1002];
int visited[1002][1002][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<Node> q;
string s;

void init()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            map[i][j + 1] = s[j] - '0';
        }
    }
    q.push({1, 1, 0, 1});
    visited[1][1][0] = 1;
}

int solution()
{
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.x == N && cur.y == M)
        {
            return cur.dist;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = cur.x + dx[i];
            int yy = cur.y + dy[i];
            if (xx < 1 || xx > N || yy < 1 || yy > M)
                continue;
            if (map[xx][yy] == 1 && cur.flag == 0)
            {
                q.push({xx, yy, cur.flag + 1, cur.dist + 1});
                visited[xx][yy][cur.flag] = 1;
            }
            else if (map[xx][yy] == 0 && visited[xx][yy][cur.flag] == 0)
            {
                visited[xx][yy][cur.flag] = 1;
                q.push({xx, yy, cur.flag, cur.dist + 1});
            }
        }
    }
    return -1;
}

int main()
{
    init();
    int result = solution();
    printf("%d\n", result);
}