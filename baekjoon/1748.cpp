#include <iostream>
#include <cmath>
using namespace std;
int n, ret;

int main(){
    cin >> n;

    for(int i=0; i<9; i++){
        double tmp = pow(10,i);
        if(n>=tmp)
            ret += (i+1)* int(min((9*tmp), n-tmp+1));
    }

    //한 자리
    if(n>0){
        ret += min(9, n);
    }
    //두 자리
    if(n>=10){
        ret += 2*min(90, n-9);
    }
    //세 자리
    if(n>=100){
        ret += 3*min(900, n-99);
    }
    //네 자리
    if(n>=1000){
        ret += 4*min(9000, n-999);
    }
    //다섯 자리
    if(n>=10000){
        ret += 5*min(90000, n-9999);
    }
    //여섯 자리
    if(n>=100000){
        ret += 6*min(900000, n-99999);
    }
    //일곱 자리
    if(n>=1000000){
        ret += 7*min(9000000, n-999999);
    }
    //여덟 자리
    if(n>=10000000){
        ret += 8*min(90000000, n-9999999);
    }
    //아홉 자리
    if(n>=100000000){
        ret += 9;
    }
    cout << ret <<"\n";
}