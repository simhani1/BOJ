import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        final int INF = 123456789;
        int[] answer = new int[targets.length];
        int[] idx = new int[30];
        // init
        for(int i=0;i<30;i++){
            idx[i] = INF;
        }
        for(String str : keymap){
            for(int i=0;i<str.length();i++){
                idx[str.charAt(i) - 'A'] = Math.min(idx[str.charAt(i) - 'A'], i + 1);
            }
        }
        for(int i=0;i<targets.length;i++){
            String target = targets[i];
            int cnt = 0;
            for(int j=0;j<target.length();j++){
                cnt += idx[target.charAt(j) - 'A'];
            }
            if(cnt >= INF)
                cnt = -1;
            answer[i] = cnt;
        }
        return answer;
    }
}