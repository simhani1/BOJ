import java.util.*;

class Solution {
    
    public int[] solution(String msg) {
        Map<String, Integer> map = new HashMap<>(); 
        List<Integer> ret = new ArrayList<>();
        int pk = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            map.put(String.valueOf(c), ++pk);
        }
        
        for (int i = 0; i < msg.length(); i++) {
            String word = "";
            while (i < msg.length()) {
                if (!map.containsKey(word + msg.charAt(i))) {
                    break;
                }
                word += msg.charAt(i);
                i++;
            }
            ret.add(map.get(word));
            if (i < msg.length()) {
                map.put(word + msg.charAt(i--), ++pk);
            }
        }
        
        int[] ans = new int[ret.size()];
        for (int i = 0; i < ret.size(); i++) {
            ans[i] = ret.get(i);
        }
        return ans; 
    }
}