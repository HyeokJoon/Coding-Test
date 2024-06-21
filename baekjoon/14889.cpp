#include <iostream>
using namespace std;

int n, mini = 10e8;
int s[21][21];
vector<int> start;
vector<int> link;
int arr[20];


int calc(){
    int sum_start = 0;
    int sum_link = 0;
    for(int i=0; i<start.size(); i++){
        for(int j=i+1; j<start.size(); j++){
            sum_start += s[start[i]][start[j]];
            sum_start += s[start[j]][start[i]];
            sum_link += s[link[i]][link[j]];
            sum_link += s[link[j]][link[i]];
        }
    }
    return abs(sum_link - sum_start);
}

void combi(int cnt){
    if(start.size() == n/2){
        int k=0;
        while(cnt < n){
            link.push_back(cnt);
            cnt++;
            k++;
        }
        mini = min(mini, calc());
        while(k!=0){
            link.pop_back();
            k--;
        }
    }
    else{
        if(cnt >n)
            return;
        start.push_back(cnt);
        combi(cnt+1);
        start.pop_back();
        link.push_back(cnt);
        combi(cnt+1);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
        arr[i] = i;
    }

    combi(0);
    cout << mini << "\n";
}