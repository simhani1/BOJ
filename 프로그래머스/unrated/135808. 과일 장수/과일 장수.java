import java.util.*;

class Solution {
    
    final int INF = 123456789;
    
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        Arrays.sort(score);
        int value = INF;
        int cnt = 0;
        for(int i=score.length-1;i>=0;i--){
            value = Math.min(value, score[i]);
            cnt++;
            if(cnt == m){
                answer += (value * m);
                value = INF;
                cnt = 0;
            }
        }
        return answer;
    }
}