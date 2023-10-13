import java.util.*;

class Solution {
    
    Map<String, Integer> m = new HashMap<>();
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        for(int i=0;i<want.length;i++){
            m.put(want[i], number[i]);
        }
        // 0 ~ 13
        // 0 ~ 9, 1 ~ 10, 2 ~ 11, 3 ~ 12, 4 ~ 13
        for(int i=0;i<=discount.length - 10;i++){
            Map<String, Integer> tmp = new HashMap<>();
            for(int j=i;j<i+10;j++){
                tmp.put(discount[j], tmp.getOrDefault(discount[j], 0) + 1);
            }
            int sum = 0;
            for(String k : m.keySet()){
                if(!tmp.containsKey(k))
                    break;
                if(m.get(k) <= tmp.get(k))
                    sum++;
            }
            if(sum == want.length)
                answer++;
        }
        return answer;
    }
}