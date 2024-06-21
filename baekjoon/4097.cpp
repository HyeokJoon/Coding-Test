#include <iostream>
#include <algorithm>
using namespace std;

int t,n, s, e;
long sum[250001],maxi;
long p[250001];
long dp[250001];

void init(){
    maxi = -20000;
    for(int i=1; i<=n; i++){
        // sum[i] = 0;
        cin >> p[i];
        maxi = max(maxi, p[i]);
        // sum[i] = sum[i-1] + p[i];
    }
}

void solution(){
    dp[1] = p[1];
    for(int i=1; i<n; i++){
        dp[i+1] = max(p[i+1], dp[i] + p[i+1]);
    }
    // s = 1;
    // e = n;
    // while(s<e){
    //     maxi = max(maxi, (sum[e]-sum[s-1]));
    //     if(p[e] > p[s])
    //         s++;
    //     else 
    //         e--;
    // }
    // cout << maxi << "\n";
    cout << max(maxi,dp[n]) << "\n";
}

int main(){
    while(1){
        cin >> n;
        if(n == 0)
            break;
        init();
        solution();
    }
}