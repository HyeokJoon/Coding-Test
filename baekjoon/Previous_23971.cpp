#include <iostream>
using namespace std;

int W, H, N, M;
int result;

void init()
{
    cin >> H >> W >> N >> M;
}
void solution()
{
    int h = H / (N + 1);
    if (H % (N + 1))
        h++;
    int w = W / (M + 1);
    if (W % (M + 1))
        w++;
    result = h * w;
}
int main()
{
    init();
    solution();
    printf("%d\n", result);
}