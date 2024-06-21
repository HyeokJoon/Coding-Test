#include <iostream>
#include <queue>
using namespace std;

int n, ret, maxi = 200;
int map[101][101];
int visited[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
queue<pair<int,int>> land_edge;
queue<pair<int,int>> q;

void init(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                land_edge.push({i,j});
                visited[i][j] = 1;
            }       
        }
    }
}
void bfs(){
    // 끝까지 이동
    while(q.size()){
        int curx = land_edge.front().first;
        int cury = land_edge.front().second;
        land_edge.pop();
        
        for(int i=0; i<4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx <0 || ny<0 || nx>=n || ny>=n)
                continue;
            
            if(visited[nx][ny])
                continue;
            

        }
    }
}

void solution(){
    
    // //하나의 섬 선택
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(visited[i][j])
    //             continue;
    //         visited[i][j] = 1;
    //         q.push({i,j});
    //         bfs();
    //     }
    // }

    while(land_edge.size()){

        int curx = land_edge.front().first;
        int cury = land_edge.front().second;
        land_edge.pop();
        
        for(int i=0; i<4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx <0 || ny<0 || nx>=n || ny>=n)
                continue;
            
            if(visited[nx][ny] == 1 && map[nx][ny] != 1)
                continue;

            if(map[nx][ny] != 0){
                ret = map[nx][ny] + map[curx][cury];
                return;
            }

            visited[nx][ny] = 1;
            map[nx][ny] = map[curx][cury] + 1;
            
        }
    }
}

int main(){
    init();
    solution();
}