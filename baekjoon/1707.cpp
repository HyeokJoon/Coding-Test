#include <iostream>
#include <vector>
using namespace std;

int t,v,e, flag=1;
int v1, v2;
int visited[20001];
vector<int> vv[20001];
bool solution(){
    cin >> v >> e;
    for(int i=0; i<e; i++){
        cin >> v1 >> v2;
        vv[v1].push_back(v2);
        vv[v2].push_back(v1);
    }
    
    for(int i=0; i<v; i++){
        if(visited[i])
            continue;

        for(int j=0; j<vv[i].size(); j++){
            //둘 다 방문 안한 경우
            if(!visited[i] && !visited[j]){
                visited[i] = 1;
                visited[j] = 2;
            }

            //i만 방문한 경우
            if(visited[i] && !visited[j])
            {
                visited[j] = visited[i] % 2 + 1;
            }

            //j만 방문한 경우   
            if(!visited[i] && visited[j]){
                visited[i] = visited[j] % 2 + 1;
            }

            //둘 다 방문한경우 check
            else{
                if(visited[i] == visited[j])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        if(!solution())
            printf("NO\n");
        else
            printf("YES\n");
    }
}