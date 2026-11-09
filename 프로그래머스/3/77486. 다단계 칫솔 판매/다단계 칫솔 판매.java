import java.util.*;

class Solution {
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        Map<String, Integer> db = new HashMap<>();        
        db.put("center", 0);
        for (int i = 0; i < enroll.length; i++) {
            db.put(enroll[i], i + 1);
        }
        
        int[] profit = new int[enroll.length + 1];

        int[] parent = new int[enroll.length + 1];

        for (int i = 0; i < enroll.length; i++) {
            if (!"-".equals(referral[i])) {
                parent[i + 1] = db.get(referral[i]);
            }
        }
        
        for (int i = 0; i < seller.length; i++) {
            String s = seller[i];
            int idx = db.get(s);
            int point = amount[i] * 100;
            
            while (idx != 0) {
                int diff = point / 10;
                profit[idx] += point - diff;
                point = diff;
                idx = parent[idx];
            }
        }
        
        int[] answer = new int[enroll.length];
        for (int i = 0; i < enroll.length; i++) {
            answer[i] = profit[i + 1];
        }
        return answer;
    }
}