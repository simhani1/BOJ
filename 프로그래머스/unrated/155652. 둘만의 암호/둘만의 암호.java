import java.util.*;

class Solution {
    
    private char originalChar;
    
    public String solution(String s, String skip, int index) {
        String answer = "";
        
        for(int i=0;i<s.length();i++){
            originalChar = s.charAt(i);
            int cnt = 0;
            while(cnt != index){
                originalChar++;
                if(originalChar > 'z'){
                    originalChar -= 26;
                }
                if(skip.contains(originalChar + "")){
                    continue;
                }
                else{
                    cnt++;
                }
            }
            answer += originalChar;
        }
        return answer;
    }
}