#include <iostream>
using namespace std;

int n, v1,v2, start;
vector<int> v[3001];
int answer[3001];
int vis[3001];
vector<int> visited;
vector<int> t;

void insert_answer(){
    for(int i=0; i<visited.size(); i++){
        if(answer[visited[i]] == 0)
            answer[visited[i]] = i+1;
        else
            answer[visited[i]] = min(i+1, answer[visited[i]]);
    }
}

void dfs(int k){
    // 순환선
    if(k == start && visited.size()){
        for(int i=0; i<visited.size(); i++){
            answer[visited[i]] = 0;
            // vis[visited[i]]++;
        }
        return;
    }

    // 종착역
    if(v[k].size() == 1){
        insert_answer();
        return;
    }

    for(int i=0; i<v[k].size(); i++){
        int next = v[k][i];
        if(vis[next]) continue;
    
        // 또다른 분기점
        for(int i=0; i<t.size(); i++){
            if(t[i] != start && t[i] == next){
                insert_answer();
                break;
            }
        }

        vis[next]+=1;
        visited.push_back(next);
        dfs(next);
        vis[next]--;
        visited.pop_back();
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    //분기점 찾기
    for(int i=1; i<=n; i++){
        if(v[i].size() > 2)
        {
            t.push_back(i);
        }
    }

    //분기점부터 시작
    for(int i=0; i<t.size(); i++){
        start = t[i];
        dfs(t[i]);
    }

    //출력
    for(int i=1; i<=n; i++){
        cout << answer[i]<<" ";
    }
}