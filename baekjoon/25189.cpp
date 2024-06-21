#include <iostream>
#include <queue>
using namespace std;

int n, m, rf, cf, rh, ch;
int curx, cury, nx, ny, flag;
int map[1010][1010];
int visited[1010][1010][2];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
queue<pair<int,pair<int,int>>> q;


void init(){
    cin >> n >> m >> rf >> cf >> rh >> ch;
    rf-=1;
    cf-=1;
    rh-=1;
    ch-=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
}

void solution(){
    if(rf == rh && cf == ch)
    {
        cout << 0 << "\n";
        return;
    }
    q.push({0,{rf, cf}});
    visited[rf][cf][0] = 1;
    visited[rf][cf][1] = 1;
    while(q.size()){
        curx = q.front().second.first;
        cury = q.front().second.second;
        flag = q.front().first;
        q.pop();


        //상하좌우
        for(int i=0; i<4; i++){
            nx = curx + dx[i]*map[curx][cury];
            ny = cury + dy[i]*map[curx][cury];

            if(nx <0 || ny <0 || nx>=n || ny >=m)
                continue;
            if(visited[nx][ny][flag])
                continue;
            if(nx == rh && ny == ch)
            {   
                cout << visited[curx][cury][flag];
                return;
            }
            visited[nx][ny][flag] = visited[curx][cury][flag] + 1;
            q.push({flag,{nx,ny}});
        }

        //슈퍼점프
        if(flag == 0){
            //x축 이동
            for(int i=0; i<m; i++){
                if(cury == i || visited[curx][i][1])
                    continue;
                if(curx == rh && i == ch)
                {   
                    cout << visited[curx][cury][flag];
                    return;
                }
                visited[curx][i][1] = visited[curx][cury][flag] + 1;
                if(visited[curx][i][0] == visited[curx][i][1])
                    continue;
                q.push({1, {curx, i}});
            }
            //y축 이동
            for(int j=0; j<n; j++){
                if(curx == j || visited[j][cury][1])
                    continue;
                if(j == rh && cury == ch)
                {   
                    cout << visited[curx][cury][flag];
                    return;
                }
                visited[j][cury][1] = visited[curx][cury][flag] + 1;
                if(visited[j][cury][0] == visited[j][cury][1])
                    continue;
                q.push({1, {j,cury}});
            }
        }

    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solution();
}