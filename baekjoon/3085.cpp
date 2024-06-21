#include <iostream>
#include <algorithm>
using namespace std;

int n,m, ret;
int x1, y, x2, y2;
int map[55][55];
int dx[4] = {1,0};
int dy[4] = {0,1};


void init(){
    string s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<s.length(); j++){
            map[i][j] = s[j];
        }
    }
}

void change(){
    int tmp = map[x1][y];
    map[x1][y] = map[x2][y2];
    map[x2][y2] = tmp;
}

void solution(){
    int max_row = 1;
    int max_col = 1;
    int rows = 0;
    int cols = 0;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            //row
            if(map[i][j] == map[i][j-1])
            {   
                rows++;
                max_row = max(max_row, rows);
            }
            else
                rows = 0;
            //col
            if(map[j][i] == map[j][i-1]){
                cols++;
                max_col = max(max_col, cols);
            }
            else
                cols = 0;
        }
        ret = max({ret, max_col, max_row});
    }
}

int main(){
    init();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x1 = i;
            y = j;
            for(int k=0; k<2; k++){
                x2 = x1 + dx[k];
                y2 = y + dy[k];
                if(x2 <0 || x2 >=n || y2<0 || y2>=n)
                    continue;
                if(map[x1][y] == map[x2][y2])
                    continue;
                change();
                solution();
                change();
            }
        }
    }
    cout << ret << "\n";

}