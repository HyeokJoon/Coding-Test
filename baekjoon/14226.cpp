#include <iostream>
using namespace std;

int s, ret;
int cnt;
int dp[1001];

void ctrlc(int k){
    cnt = k;
}

void ctrlv(int idx){
    int n=0;
    for(int i=idx; i<1000; i+=cnt){
        dp[i] = min(dp[idx], dp[i]+n);
        n++;
    }
}

int main(){
    cin >> s;
    for(int i=0; i<1000; i++)
        dp[i] = 1000;
    
    int muls = 0; //곱하기 2횟수
    int minus = 0; //빼기 1횟수

    dp[1] = 0;
    for(int i=1; i<s; i++){
        //복사 붙여넣기
        ctrlc(i);
        ctrlv(i);

        //빼기

        
    }
    
}