#include <iostream>
using namespace std;

int n,m, num1, num2, flag;
int parent[1000003];

int findParent(int x){
    if(parent[x] == x)
        return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a>b)
        parent[a] = b;
    else 
        parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    
    for(int i=0; i<m; i++){
        cin >> flag >> num1 >> num2;
        if(flag){
            if(findParent(num1) == findParent(num2))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else{
            unionParent(num1,num2);
        }
    }
}