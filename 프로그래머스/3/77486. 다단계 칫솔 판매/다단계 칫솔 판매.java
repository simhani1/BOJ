import java.util.*;

class Solution {
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        Map<String, Integer> db = new HashMap<>();        
        int pk = 0;
        db.put("center", pk);
        for (int i = 0; i < enroll.length; i++) {
            db.put(enroll[i], ++pk);
        }
        
        int[] profit = new int[pk + 1];
        
        int[] parent = new int[pk + 1];
        for (int i = 0; i <= pk; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < enroll.length; i++) {
            String a = enroll[i];
            String b = referral[i];
            if ("-".equals(b)) {
                parent[db.get(a)] = 0;
            } else {
                parent[db.get(a)] = db.get(b);
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
            answer[i] = profit[db.get(enroll[i])];
        }
        return answer;
    }
}