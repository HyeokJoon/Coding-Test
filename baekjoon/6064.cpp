#include <iostream>
using namespace std;

int t,m,n,x,y;

int lcm(int a, int b)
{
    int x = a;
    while(x%b != 0)
        x+=a;
    return x;
}

int solution(){
    return (n * (n % m) * x) + (m * (m%n) * y) / lcm(m,n);
}

int main(){
    cin >> t;
    for(int tc=0; tc<t; tc++){
        cin >> m >> n >> x >> y;
        cout << solution() << "\n";
    }
}