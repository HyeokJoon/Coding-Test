#include <iostream>
#include <queue>
using namespace std;

int tc,l,sx,sy,ex,ey;
queue<pair<int, pair<int,int>>> q; //이동횟수, x, y
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
bool visited[301][301];

void init(){
    cin >> l;
    cin >> sx >> sy >> ex >> ey;
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            visited[i][j] = false;
        }
    }
    while(q.size()){
        q.pop();
    }
}

void solution(){
    q.push({0,{sx,sy}});
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();
        if(x == ex && y==ey)
        {
            cout << cnt << "\n";
            break;
        }
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny <0 || nx>=l || ny>=l || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({cnt+1,{nx,ny}});
        }
    }
}

int main(){
    cin >> tc;
    for(int i=0; i<tc; i++){
        init();
        solution();
    }   
}