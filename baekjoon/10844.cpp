#include <iostream>
using namespace std;
int n,ret;
int dp[101][10];//길이가 n이고 끝이 k인 계단수 개수


int main(){
    cin >> n;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }


    for(int i=2; i<=100; i++){
        for(int k=0; k<10; k++){
            if(k==0)
                dp[i][k] = dp[i-1][k+1] % 1000000000;
            else if(k==9)
                dp[i][k] = dp[i-1][k-1]% 1000000000;
            else
                dp[i][k] = (dp[i-1][k-1] + dp[i-1][k+1])% 1000000000;
        }
    }
    
    for(int i=0; i<10; i++){
        ret = (ret+dp[n][i]) % 1000000000;
    }
    cout << ret << "\n";
}