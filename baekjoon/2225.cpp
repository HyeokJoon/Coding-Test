#include <iostream>
#include <queue>
using namespace std;

int n,k;
int dp[202][202];


int solution(){

    //dp[n][k] : 숫자 n을 만드는데 k번 더한 경우
    //dp[n][k] = for (dp[n-i][k-1]);
    for(int i=0; i<=n; i++)
        dp[i][1] = 1;
    for(int i=0; i<=n; i++){
        for(int j=1; j<k; j++){
            for(int gap = 0; gap<=n; gap++){
                if(i+gap >n)
                    break;
                dp[i+gap][j+1] = (dp[i+gap][j+1] + dp[i][j]) % 1000000000;
            }
        }
    }
    return dp[n][k];
}

int main(){

    cin >> n >> k;
    cout << solution() << "\n";

}