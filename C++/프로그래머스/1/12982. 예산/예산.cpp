#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());

    bool loop = true;
    while(loop){
        for (int i=0; i<d.size(); i++){
            // cout << "request: " << d[i] <<", budget: "<<budget << endl;
            if(budget >= d[i]){
                budget -= d[i];
                answer++;
                continue;
            }
            else{
                break;
            }
        }
        loop = false;
    }
    
    return answer;
}