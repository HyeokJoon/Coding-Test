#include <iostream>
using namespace std;

int e,s,m,result;

int main(){
    cin >> e >> s >> m;
    while(1){
        if (result %15 +1 != e || result %19 +1  != m || result %28 +1  != s)
            result++;
        else 
            break;
    }
    cout << result+1 << "\n";
}