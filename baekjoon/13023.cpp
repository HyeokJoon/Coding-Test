#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, ret;
vector<int> v[2001];
int visited[2020];

void dfs(int k, int cnt){
    if(ret == 1)
        return;
    if(cnt == 5){
        ret = 1;
    
        // cout << ret << "\n";
        // exit(0);
    }
    for(int i : v[k]){
        if(ret == 1)
            break;
        if(!visited[i]){
            visited[i] = 1;
            dfs(i, cnt+1);
            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        if(ret == 1)
            break;
        visited[i] = 1;
        dfs(i, 1);
        visited[i] = 0;
    }

    cout << ret << "\n";

}