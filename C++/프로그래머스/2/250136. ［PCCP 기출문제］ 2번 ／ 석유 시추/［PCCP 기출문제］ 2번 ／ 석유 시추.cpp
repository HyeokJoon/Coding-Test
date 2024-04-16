#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int visited[501][501];
vector<int> cols;

void bfs(int x, int y, vector<vector<int>>& land){
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 1;
    int min_col = y;
    int max_col = y;
    
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        // cout << " curx: " << curx << " cury: " << cury << endl;
        for(int i=0; i<4; i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];

            if (nx<0 || ny<0 || nx >= land.size() || ny >= land[0].size())
                continue;
            if (land[nx][ny] == 0 || visited[nx][ny]==1)
                continue;
            visited[nx][ny]=1;
            cnt++;
            min_col = min(min_col, ny);
            max_col = max(max_col, ny);
            q.push({nx,ny});
        }  
    }
    for (int i=min_col ; i<= max_col; i++){
        cols[i] += cnt;
    }
    // cout << cnt << endl;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    
    for(int i=0; i<land[0].size(); i++)
        cols.push_back(0);
    
    // bfs(0,0,land);
    
    for (int i=0; i<land.size(); i++){
        for (int j=0; j<land[0].size(); j++){
            // cout << land[i][j];
            if (land[i][j] == 1 && visited[i][j]==0){
                // cout << "[start] i : " << i << " j: " << j <<endl;
                visited[i][j] = 1;
                bfs(i,j, land);
            }
        }
    }
    
    for(int i=0; i<cols.size(); i++){
        answer = max(answer,cols[i]);
    }
    
    
    return answer;
}