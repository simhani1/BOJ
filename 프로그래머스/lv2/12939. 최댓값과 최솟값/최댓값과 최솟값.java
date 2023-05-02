import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] scoreToString = s.split(" ");
        int[] scoreToInt = new int[scoreToString.length];
        
        for (int i = 0; i < scoreToString.length; i++) {
            scoreToInt[i] = Integer.parseInt(scoreToString[i]);
        }
        
        Arrays.sort(scoreToInt);
        answer+=scoreToInt[0];
        answer+=" ";
        answer+=scoreToInt[scoreToString.length - 1];
        return answer;
    }
}