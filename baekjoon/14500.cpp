#include <iostream>
using namespace std;

int n,m, maxi;
int map[505][505];
int visited[505][505];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void init(){
    cin >> n >>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
}

void dfs(int cnt, int ret, int x, int y){
    if (cnt == 4){
        maxi = max(maxi, ret);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny <0 || nx>=n || ny>=m ||visited[nx][ny])
            continue;
        visited[nx][ny] = 1;
        dfs(cnt+1, ret+map[nx][ny], nx, ny);
        if(cnt == 2)
            dfs(cnt+1, ret+map[nx][ny], x, y);
        visited[nx][ny] = 0;
    }
    
    
}

// void checkT(int x, int y){
//     int sum;
//     //'ㅗ' 모양
//     if(x>0 && y>0 && y<m-1){        
//         sum = map[x][y] + map[x-1][y] + map[x][y-1] + map[x][y+1];
//         maxi = max(sum, maxi);
//     }
//     //'ㅜ' 모양
//     if(x<n-1 && y>0 && y<m-1){        
//         sum = map[x][y] + map[x+1][y] + map[x][y-1] + map[x][y+1];
//         maxi = max(sum, maxi);
//     }
//     //'ㅏ' 모양
//     if(x>0 && x<n-1 && y<m-1){
//         sum = map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y+1];
//         maxi = max(sum, maxi);
//     }
//     //'ㅓ' 모양
//     if(x>0 && x<n-1 && y>0){
//         sum = map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y-1];
//         maxi = max(sum, maxi);
//     }
// }

void solution(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = 1;
            dfs(1,map[i][j], i,j);
            visited[i][j] = 0;
            // checkT(i,j);
        }
    }
}


int main(){
    init();
    solution();
    cout << maxi << "\n";
}