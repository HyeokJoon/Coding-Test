#include <iostream>
using namespace std;

int t, n, m, a, b;

void solution(){
    cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> a >> b;
    cout << n-1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int tc = 0; tc<t; tc++)
        solution();
}