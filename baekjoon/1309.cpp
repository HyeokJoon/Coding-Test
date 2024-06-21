#include <iostream>
using namespace std;
int n;
int dp[100010][3]; // 0:없음, 1:오른쪽칸, 2:왼쪽칸

int main(){
    int answer = 0;
    //초기화
    cin >> n;
    for(int i=0; i<3; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    for(int i=0; i<3; i++){
        answer = (answer + dp[n][i]) % 9901;
    }
    cout << answer << "\n";

}