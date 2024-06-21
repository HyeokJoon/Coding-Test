#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,k, next_, cur;
int visited[100001];
queue<int> q;
vector<int> v;

void print_answer(int cur){
    int i = cur;
    while(visited[i]!=-1){
        v.push_back(i);
        i = visited[i];
    }
    v.push_back(n);

    cout << v.size()-1 << "\n";
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << " ";
    }
}

int main(){
    cin >> n >> k;

    visited[n] = -1;
    q.push(n);

    while(q.size()){
        cur = q.front();
        q.pop();

        if(cur >= 1 && visited[cur-1]==0){
            next_ = cur-1;
            visited[next_] = cur;
            if(next_ == k)
            {
                print_answer(next_);
                break;
            }
            q.push(next_);
        }

        if(cur > k)
            continue;

        if(cur <= 99999 && visited[cur+1]==0){
            next_ = cur+1;
            visited[next_] = cur;
            if(next_ == k)
            {
                print_answer(next_);
                break;
            }
            q.push(next_);
        }

        if(cur <= 50000 && visited[cur*2]==0){
            next_ = cur*2;
            visited[next_] = cur;
            if(next_ == k)
            {
                print_answer(next_);
                break;
            }
            q.push(next_);
        }
    }
}