#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> endDate;
    for(int i=0; i<progresses.size(); i++){
        int date = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i] != 0)
            date ++;
        endDate.push_back(date);
        // cout << "date : " << date << endl;
    }
    
    int cnt = 0;
    int cur = endDate[0];
    for(int i=0; i<endDate.size(); i++){
        if (cur >= endDate[i])
        {
            cnt++;
        }
        else{
            answer.push_back(cnt);
            cnt = 1;
            cur = endDate[i];
        }
    }
    
    answer.push_back(cnt);
    
    
    return answer;
}