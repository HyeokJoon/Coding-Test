#include <iostream>
using namespace std;

int arr[21];
int n, operand, k=1;
string oper;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> oper;
        if(oper == "add"){
            cin >> operand;
            arr[operand] = k;
        }
        else if(oper == "remove"){
            cin >> operand;
            arr[operand] = 0;
        }
        else if(oper == "check"){
            cin >> operand;
            cout << (arr[operand] == k) << "\n";
        }
        else if(oper == "toggle"){
            cin >> operand;
            if(arr[operand] ==k)
                arr[operand] = 0;
            else
                arr[operand] = k;
        }
        else if(oper == "all"){
            for(int j=1; j<=20; j++){
                arr[j] = k;
            }
        }
        else if(oper == "empty"){
            k++;
        }
        else
            break;
    }
}