#include <iostream>
#include <queue>
using namespace std;

int w, h, cnt;
int map[51][51];
int visited[51][51];
int dx[8] = {-1,0,1,0, -1,-1,1,1};
int dy[8] = {0,-1,0,1, -1,1,-1,1};
queue<pair<int, int>> q;


void bfs(int x, int y){
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<0 || ny <0|| nx >= h || ny >=w || visited[nx][ny] || map[nx][ny]==0)
                continue;
            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }

}

int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0)
            break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        cnt = 0;


        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j] || map[i][j] == 0)
                    continue;
                visited[i][j] = 1;
                cnt++;
                bfs(i,j);
            }
        }

        cout << cnt << "\n";
    }
}