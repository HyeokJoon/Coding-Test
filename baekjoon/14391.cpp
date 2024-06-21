#include <iostream>
using namespace std;

int n,m;
int maxi, sum;
string s;
int map[4][4];
int visited[4][4];


void dfs(int i, int j, int total){
    //마지막 경우의 수
    if(i==4 && j==4){
        
    }

    //가로로 자를 경우
    int sum = 0;
    for(int k=j; k<m; k++){
        int ii = i;
        int jj = j;

        sum = sum*10 + map[i][k];
        visited[i][k] = 1;

        for(; ii<n; ii++){
            for(; jj<m; jj++){
                if(visited[ii][jj])
                    continue;
                visited[ii][jj] = 1;
                dfs(ii,jj,total + sum);
                visited[ii][jj] = 0;
            }   
        }
        maxi = max(maxi, total+sum);
    }


    //세로로 자를 경우
    sum = 0;
    for(int k=i; k<n; k++){
        int ii = i;
        int jj = j;

        sum = sum*10 + map[k][m];
        visited[k][m] = 1;

        for(; ii<n; ii++){
            for(; jj<m; jj++){
                if(visited[ii][jj])
                    continue;
                visited[ii][jj] = 1;
                dfs(ii,jj,total + sum);
            }   
        }
        maxi = max(maxi, total+sum);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    dfs(0,0, 0);
    cout << maxi << "\n";
}