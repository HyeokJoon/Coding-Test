//문제 있음 아직 미완성
#include <iostream>
using namespace std;

class weight
{
public:
    int check = 0;
    int x = 0;
    int y = 0;
};
int main()
{
    int T, N, M;
    cin >> T >> N >> M;
    int arr[N + 1];
    weight graph[N + 1][N + 1];
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            graph[i][j].x = 0;
            graph[i][j].y = 0;
        }
        arr[i] = 0;
    }
    // for (int i = 1; i < N + 1; i++)
    // {
    //     for (int j = 1; j < N + 1; j++)
    //     {
    //         cout << "(" << graph[i][j].x << " " << graph[i][j].y << ") ";
    //     }
    //     cout << endl;
    // }
    while (T > 0)
    {
        if (M == 0)
        {
            T--;
            continue;
        }
        for (int j = 0; j < M; j++)
        {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            graph[a][b].check = 1;
            graph[a][b].x = x;
            graph[a][b].y = y;
            graph[b][a].x = x;
            graph[b][a].y = y;
            if (arr[a] == 1)
            {
                for (int j = 1; j < N + 1; j++)
                {
                    int min;
                    if (graph[a][j].check == 1)
                    {
                        min = (graph[a][j].x + graph[a][b].x) * (graph[a][j].y + graph[a][b].y);
                        if (graph[b][j].x == 0)
                        {
                            graph[b][j].x = graph[a][j].x + graph[a][b].x;
                            graph[b][j].y = graph[a][j].y + graph[a][b].y;
                            graph[j][b].x = graph[b][j].x;
                            graph[j][b].y = graph[b][j].y;
                        }
                        else if ((min > (graph[b][j].x * graph[b][j].y)) && (graph[b][j].check == 1))
                        {
                            min = graph[b][j].x * graph[b][j].y;
                            graph[b][j].x = graph[a][j].x + graph[a][b].x;
                            graph[b][j].y = graph[a][j].y + graph[a][b].y;
                            graph[j][b].x = graph[b][j].x;
                            graph[j][b].y = graph[b][j].y;
                        }
                    }
                }
            }
            if (arr[b] == 1)
            {
                for (int j = 1; j < N + 1; j++)
                {
                    int min;
                    if (graph[b][j].check == 1)
                    {
                        min = (graph[b][j].x + graph[a][b].x) * (graph[b][j].y + graph[a][b].y);
                        if (graph[a][j].x == 0)
                        {
                            graph[a][j].x = graph[b][j].x + graph[a][b].x;
                            graph[a][j].y = graph[b][j].y + graph[a][b].y;
                            graph[j][a].x = graph[a][j].x;
                            graph[j][a].y = graph[a][j].y;
                        }
                        else if ((min > (graph[a][j].x * graph[a][j].y)) && (graph[a][j].check == 1))
                        {
                            min = graph[a][j].x * graph[a][j].y;
                            graph[a][j].x = graph[b][j].x + graph[a][b].x;
                            graph[a][j].y = graph[b][j].y + graph[a][b].y;
                            graph[j][a].x = graph[a][j].x;
                            graph[j][a].y = graph[a][j].y;
                        }
                    }
                }
            }
            arr[a] = 1;
            arr[b] = 1;
            // for (int i = 1; i < N + 1; i++)
            // {
            //     for (int j = 1; j < N + 1; j++)
            //     {
            //         cout << "(" << graph[i][j].x << " " << graph[i][j].y << ") ";
            //     }
            //     cout << arr[i] << endl;
            // }
        }
        int w = graph[1][2].x * graph[1][2].y;
        if (w == 0)
            w = -1;
        cout << w << endl;
        T--;
    }
}
