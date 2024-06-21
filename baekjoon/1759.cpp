#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int l,c, flag;
vector<char> v;
int visited[28];
char answer[20];

bool isvalid(){
    int cnt_mo = 0;
    int cnt_ja = 0;
    for(int i=0; i<l; i++){
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' ||v[i]=='o' ||v[i]=='u')
            cnt_mo++;
        else
            cnt_ja++;
    }
    if(cnt_ja > 1 && cnt_mo >0)
        return true;
    return false;
}

void dfs(int cnt, int idx)
{
    if (cnt == l)
    {
        if (!isvalid())
            return;
        for (int i = 0; i < l; i++)
            printf("%c", answer[i]);
        printf("\n");
    }
    else
    {
        for (int i = idx; i < c; i++)
        {
            if (!visited[v[i] - 'a'])
            {
                visited[v[i] - 'a'] = 1;
                answer[cnt] = v[i];
                dfs(cnt + 1, i);
                visited[v[i] - 'a'] = 0;
            }
        }
    }
}

int main(){
    cin >> l >> c;
    char input;
    for(int i=0; i<c; i++){
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());
    dfs(0,0);
}