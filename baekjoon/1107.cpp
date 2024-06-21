#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n, m, result;
int isbreak[11];

bool isNotValid(int a){
    while(a>0){
        int num = a%10;
        if(isbreak[num])
            return true;
        a/=10;
    }
    return false;
}

int calcUp(){
    int k = n;
    int cnt = 0;
    while(isNotValid(k)){
        k++;
        cnt++;
        if(k==1000000)
            return k;
    }
    while(k >0){
        k/=10;
        cnt++;
    }
    return cnt;
}

int calcDown(){
    int k = n;
    int cnt = 0;
    while(isNotValid(k) && k>0){
        k--;
        cnt++;
    }
    if(k==0)
        cnt++;
    while(k>0){
        k/=10;
        cnt++;
    }
    return cnt;
}
int main(){
    cin >> n >> m;

    int tmp;
    for(int i=0; i<m; i++){
        cin >> tmp;
        isbreak[tmp] = 1;
    }
    if(n == 100)
        result = 0;
    else
        result = min ({calcUp(), calcDown(), abs(100-n)});
    cout << result <<"\n";

}