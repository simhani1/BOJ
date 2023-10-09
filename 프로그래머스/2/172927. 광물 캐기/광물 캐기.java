import java.util.*;

class Solution {
    
    final int INF = 123456789;
    int answer = INF;
    
    public int solution(int[] picks, String[] minerals) {
        for(int i=0;i<picks.length;i++){
            // 곡괭이 없는 경우
            if(picks[i] == 0)
                continue;
            picks[i]--;
            dfs(0, i, 0, picks, minerals);
            picks[i]++;
        }
        return answer;
    }
    
    private void dfs(int now, int type, int sum, int[] picks, String[] minerals){
        for(int i=now;i<now+5;i++){
            // 광물을 다 캔 경우 종료
            if(i == minerals.length)
                break;
            String target = minerals[i];
            // 다이아 곡괭이
            if(type == 0)
                sum += 1;
            // 철 곡괭이
            if(type == 1){
                if(target.equals("diamond"))
                    sum += 5;
                else
                    sum += 1;
            }
            // 돌 곡괭이
            if(type == 2){
                if(target.equals("diamond"))
                    sum += 25;
                else if(target.equals("iron"))
                    sum += 5;
                else
                    sum += 1;
            }
        }
        // 광물을 다 캤거나, 곡괭이를 다 쓴 경우
        if(now + 5 >= minerals.length || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)){
            answer = Math.min(answer, sum);
            return;
        }
        for(int i=0;i<3;i++){
            if(picks[i] == 0)
                continue;
            picks[i]--;
            dfs(now + 5, i, sum, picks, minerals);
            picks[i]++;
        }
    }
}