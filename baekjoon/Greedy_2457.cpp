#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
class Flower
{
public:
    int sMonth;
    int sDay;
    int eMonth;
    int eDay;
    int idx = 0;
    // 끝나는 날 기준으로 정렬 하기 위해
    bool operator<(const Flower &others) const
    {
        if (this->sMonth == others.sMonth)
        {
            return this->sDay < others.sDay;
        }
        else
            return this->sMonth < others.sMonth;
    }
    bool operator==(const Flower &others) const
    {
        return (this->sDay == others.sDay) && (this->sMonth == others.sMonth);
    }
};
vector<Flower> flowers;

void init()
{
    int sM;
    int sD;
    int eM;
    int eD;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> sM >> sD >> eM >> eD;
        flowers.push_back({sM, sD, eM, eD});
    }
}
Flower find_flower(int idx, int m, int d)
{
    Flower f = {0, 0, 0, 0, 0};
    for (int i = idx; i < flowers.size(); i++)
    {
        if (flowers[i].sMonth > m || (flowers[i].sMonth == m && flowers[i].sDay > d))
        {
            break;
        }
        if (flowers[i].eMonth > f.eMonth)
        {
            f = flowers[i];
            f.idx = i;
        }
        else if (flowers[i].eMonth == f.eMonth && flowers[i].eDay > f.eDay)
        {
            f = flowers[i];
            f.idx = i;
        }
    }
    return f;
}

int solution()
{
    int cur_m = 3;
    int cur_d = 1;
    int cnt = 0;
    Flower f;
    sort(flowers.begin(), flowers.end());

    for (int i = 0; i < flowers.size(); i++)
    {
        if (f.eMonth > 11)
        {
            break;
        }
        f = find_flower(f.idx, cur_m, cur_d);
        if (f.eDay == 0)
        {
            return 0;
        }
        cnt++;
        cur_m = f.eMonth;
        cur_d = f.eDay;
    }
    if (cur_m < 12)
    {
        return 0;
    }
    return cnt;
}

int main()
{
    init();
    int result = solution();
    printf("%d\n", result);
}