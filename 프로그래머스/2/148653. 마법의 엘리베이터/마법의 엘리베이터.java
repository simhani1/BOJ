import java.util.*;

class Solution {
    
    int answer = 0;
        
    public int solution(int storey) {
        int now = 0;
        while(storey > 0){
            now = storey % 10;
            storey /= 10;
            System.out.println("now: " + now + " storey: " + storey);
            // 올라가기 -> 자리올림
            if(now > 5){
                storey++;
                answer += (10 - now);
            }
            // 내려가기
            else if(now < 5)
                answer += now;
            else{
                int next = storey % 10;
                // 올라가기 -> 자리올림
                if(next >= 5){
                    storey++;
                    answer += (10 - now);
                }
                // 내려가기
                else
                    answer += now;
            }
        }
        return answer;
    }
}
