#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[5005];

int solution(int n) {
    int answer = 0;
    //dp[n] = dp[n-2]*3 + dp[n-4]*2 + dp[n-6]*2 + ...
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    
    for(int i=6; i<=n; i++){
        dp[i] = dp[i-2]*3;
        
        int num = i-4;
        while(num>=0){
            dp[i] = dp[i]+(dp[num]*2);
            num -=2;
        }
        dp[i] %=1000000007;
        // cout << "dp[" << i << "] : " << dp[i] << endl;
    }
    answer = dp[n];
    
    return answer;
}