#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int visited[501][501];


void bfs(int x, int y, vector<vector<int>>* land){
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 0;
    int min_col = 500;
    int max_col = 0;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().first;
        for(int i=0; i<4; i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];

            if (nx<0 || ny<0 || nx > land->size() || ny > land[0].size())
                continue;
            if (visited[nx][ny])
                continue;
            visited[nx][ny]=1;
            cnt++;
            min_col = min(min_col, ny);
            max_col = max(max_col, ny);
        }  
    }
    for (int i=min_col ; i< max_col; i++){
        cols[i] += cnt;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<int> cols(0,land[0].size());
    
    for (int i=0; i<land.size(); i++){
        for (int j=0; j<land[0].size(); j++){
            // cout << land[i][j];
            if (visited[i][j]==0){
                visited[i][j] = 1;
                bfs(i,j,&land);
            }
        }
    }
    
    return answer;
}


int main(){
    vector<vector<int>> land;

}