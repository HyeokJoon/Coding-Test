#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int max_health = health;
    int attack_time = attacks[0][0];
    int damage = attacks[0][1];
    int attack_idx = 0;
    int success_cnt = 0;
    int time = 0;
    bool dead = false;
    
    while(1){
        // cout << time << " 체력 : " << health << " 연속성공 : " << success_cnt <<"다음공격 : " << attack_time << " 대미지 : " << damage << endl;
        
        //공격시간이면 공격
        if (attack_time == time){
            health -= damage;
            success_cnt = 0;
            
            //죽으면 break
            if (health <= 0)
            {
                dead = true;
                break;
            }
            attack_idx++;
            
            //마지막 공격이었으면 break
            if (attack_idx > attacks.size()-1){
                break;
            }
            
            //마지막 공격이 아니면 공격시간 업데이트
            attack_time = attacks[attack_idx][0];
            damage = attacks[attack_idx][1];
            time++;
            continue;
        }
        
        
        //체력 회복
        health += bandage[1];
        success_cnt++;
        
        //연속 성공하면
        if (success_cnt == bandage[0]){
            success_cnt = 0;
            health += bandage[2];
        }
        
        //최대 체력보다 높으면 
        if (max_health < health){
            health = max_health;
        }
        
        time++;
    }
    
    if(dead)
        answer = -1;
    else
        answer = health;
    
    return answer;
}