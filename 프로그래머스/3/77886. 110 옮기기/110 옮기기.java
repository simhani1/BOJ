import java.util.*;

class Solution {
    public String[] solution(String[] s) {
        
        String[] answer = new String[s.length];
        for (int i = 0; i < s.length; i++) {
            answer[i] = solve(s[i]);
        }
        return answer;
    }
    
    String solve(String str) {
        StringBuilder sb = new StringBuilder();
        
        int len = 0, cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            len++;
            if (len >= 3 && sb.substring(len - 3).equals("110")) {
                sb.delete(len - 3, len);
                len -= 3;
                cnt++;
            }
        }
        
        int idx = sb.lastIndexOf("0");
        StringBuilder result = new StringBuilder();
        result.append(sb.substring(0, idx + 1));
        for (int i = 0; i < cnt; i++) {
            result.append("110");
        }
        result.append(sb.substring(idx + 1));
        return result.toString(); 
    }
}