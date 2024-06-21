#include <iostream>
using namespace std;

int k, flag;
char input[10];
int visited[10];
char selected[11];
string mini, maxi;

bool isvalid(int cnt, int i){
    if(input[cnt-1] == '>'){
        if(selected[cnt-1] > i + '0')
            return true;
    }
    else{
        if(selected[cnt-1] < i + '0')
            return true;
    }
    return false;
}

void dfs(int cnt){
    if(cnt == k+1){
        selected[cnt] = '\0';
        if(flag == 0){
            mini = selected;
            flag = 1;
        }
        else{
            maxi = selected;
        }
        return;
    }
    for(int i=0; i<10; i++){
        if(visited[i])
            continue;
        if(isvalid(cnt,i))
        {
            visited[i] = 1;
            selected[cnt] = i + '0';
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> input[i];
    }

    for(int i=0; i<10; i++){
        visited[i] = 1;
        selected[0] = i + '0';
        dfs(1);
        visited[i] = 0;
    }
    cout << maxi << "\n" << mini << "\n";
}