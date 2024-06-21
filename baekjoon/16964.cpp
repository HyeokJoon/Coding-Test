#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, v1, v2;
vector<int> v[100001];
bool visited[100001];
vector<int> ans;
int ans_cnt2 = 0;

bool check1(int k){
    int ans_cnt = 0;
    stack<int> s;
    s.push(k);
    while(s.size()){
        int curr = s.top();
        s.pop();

        /* 정답 확인 */
        if(curr != ans[ans_cnt++])
            return false;

        /* stack에 추가 */
        for(int i=0; i<v[curr].size(); i++){
            int next = v[curr][i];
            if(visited[next])
                continue;
            visited[next] = true;
            s.push(next);
        }
    }
    return true;
}

bool check2(int k){
    if(k != ans[ans_cnt2++])
        return false;

    for(int i=0; i<v[k].size(); i++){
        int next = v[k][i];
        if(visited[next])
            continue;
        visited[next] = true;
        if(!check2(next))
            return false;
    }
    return true;
}

bool isvalid(int k){
    
}

int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    int k;
    for(int i=0; i<n; i++){
        cin >> k;
        ans.push_back(k);
        sort(v[i].begin(), v[i].end());
    }

    // visited[1] = true;
    // if(check1(1))
    //     cout << 1 << "\n";
    // else{
    //     for(int i=2; i<n; i++){
    //         visited[i] = false;
    //     }
    //     if(check2(1))
    //         cout << 1 << "\n";
    //     else
    //         cout << 0 << "\n";
    // }
    if(isvalid(1))
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}