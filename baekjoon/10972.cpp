#include <iostream>
#include <algorithm>
using namespace std;

int n, tmp;
vector<int> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    if (next_permutation(v.begin(), v.end())){
        for(int i=0; i<n; i++)
            cout << v[i] << ' ';
    }
    else
        cout << -1;
}   