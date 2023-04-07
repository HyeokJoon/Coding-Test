#include <iostream>
#include <vector>
using namespace std;

class Path
{
public:
    int start;
    int end;
    int dist;
    void set(int s, int e, int d)
    {
        this->start = s;
        this->end = e;
        this->dist = d;
    }
};

int N, D;
vector<Path> paths;
int Dist[10001];
Path path[12];

void init()
{
    scanf("%d %d", &N, &D);
    int s, e, d;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &s, &e, &d);
        if (e - s < d || e > D)
            continue;
        path[i].set(s, e, d);
        paths.push_back(path[i]);
    }
}

void findDist()
{
    Dist[0] = 0;
    int cur = 0;
    for (int j = 1; j <= D; j++)
    {
        Dist[j] = Dist[j - 1] + 1;
        for (int i = 0; i < paths.size(); i++)
        {
            if (paths[i].end == j && Dist[j] > (paths[i].dist + Dist[paths[i].start]))
            {
                Dist[j] = paths[i].dist + Dist[paths[i].start];
            }
        }
    }
    printf("%d\n", Dist[D]);
}

int main()
{
    // freopen("baekjoon/input.txt", "r", stdin);
    init();
    findDist();
}