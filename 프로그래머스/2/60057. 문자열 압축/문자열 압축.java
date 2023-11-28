import java.util.*;

class Solution {
    
    int N;
    int answer;
    
    public int solution(String s) {
        N = s.length();
        answer = N;
        for(int i=1;i<=N/2;i++){
            int cnt = 1;
            String result = "";
            String base = s.substring(0, i);
            for(int j=i;j<=N;j+=i){
                int idx = Math.min(j+i, N);
                String target = s.substring(j, idx);
                if(base.equals(target))
                    cnt++;
                else{
                    if(cnt >= 2)
                        result += String.valueOf(cnt);
                    result += base;
                    base = target;
                    cnt = 1;
                }
            }
            result += base;
            answer = Math.min(answer, result.length());
        }
        return answer;
    }
}