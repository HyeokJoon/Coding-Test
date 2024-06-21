#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<char> st;
string s, check_str;

void check(){
    stack<char> tmp;
    for(int idx = check_str.size()-1; idx >=0; idx--){
        if(st.top() != check_str[idx]){
            while(tmp.size())
            {
                st.push(tmp.top());
                tmp.pop();
            }
            return;
        }
        else{
            tmp.push(st.top());
            st.pop();
        }
    }
    //폭발
    return;
}

int main(){
    cin >> s >> check_str;
    for(int i=0; i<s.size(); i++){
        st.push(s[i]);
        if(st.size() >= check_str.size() && st.top() == check_str[check_str.size()-1])
            check();
    }
    
    if(st.empty())
    {
        cout << "FRULA";
        return 0;
    }
    
    vector<char> answer;
    while(st.size()){
        answer.push_back(st.top());
        st.pop();
    }
    for(int i=answer.size(); i>=0; i--)
        cout << answer[i];
}