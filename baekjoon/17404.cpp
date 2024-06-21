#include <iostream>
#include <algorithm>
using namespace std;

int n,result = 100000000;
int cost[1010][3];
int dp[1010][3];
void init(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = cost[i][j];
        }
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int k=0; k<3; k++){

        init();

        dp[0][0] = 100000000;
        dp[0][1] = 100000000;
        dp[0][2] = 100000000;
        dp[0][k] = dp[n][k];

        for(int i=1; i<n; i++){
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
        }
        
        result = min({result, dp[n-1][(k+1) % 3], dp[n-1][(k+2) % 3]});
    }

    cout << result;
}