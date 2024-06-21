#include <iostream>
#include <algorithm>
using namespace std;

int n,mini = 10e8;
int s[21][21];
vector<int> start;
vector<int> link;

void calc(){
    int link_sum = 0;
    int start_sum = 0;
    for(int i=0; i<start.size(); i++){
        for(int j=i+1; j<start.size(); j++){
            start_sum += s[start[i]][start[j]] + s[start[j]][start[i]];
        }
    }

    for(int i=0; i<link.size(); i++){
        for(int j=i+1; j<link.size(); j++){
            link_sum += s[link[i]][link[j]] + s[link[j]][link[i]];       
        }
    }
    mini = min(mini, abs(link_sum-start_sum));
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }

    for(int i=0; i<(1<<(n+1)); i++){
        start.clear();
        link.clear();
        for(int j=0; j<n; j++){
            if((1<<j) & i){
                start.push_back(j);
            }
            else{
                link.push_back(j);
            }
        }
        c alc();
    }
    cout << mini <<"\n";
}