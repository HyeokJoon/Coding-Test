#include <iostream>
#include <set>
using namespace std;

int s1, s2, a;
set<int> S1;

int main(){
    cin >> s1 >> s2;
    int cnt = 0;
    for(int i=0; i<s1; i++){
        cin >> a;
        S1.insert(a);
    }

    for(int i=0; i<s2; i++){
        cin >> a;
        if(S1.find(a) != S1.end())
            cnt++;
    }

    cout << s1+s2-2*cnt;
}