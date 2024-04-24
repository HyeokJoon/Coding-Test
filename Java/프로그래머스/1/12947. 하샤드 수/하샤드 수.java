class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int tmp = x;
        int sum = 0;
        while(tmp>0){
            sum += tmp%10;
            tmp /= 10;
        }
        if(x%sum == 0)
            return answer;
        return false;
    }
}