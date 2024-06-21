#include <iostream>
using namespace std;

int n,r,g,b;
int dp[1001][3];

int main(){
    cin >> n;
    cin >> r >> g >> b;
    dp[1][0] = r;
    dp[1][1] = g;
    dp[1][2] = b;

    for(int i=2; i<=n; i++){
        cin >> r >> g >> b;
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
    }
    int ret = min(dp[n][0],dp[n][1]);
    ret = min(ret, dp[n][2]);
    cout << ret << "\n";
}