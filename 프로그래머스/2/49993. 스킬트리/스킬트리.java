import java.util.*;

class Solution {
    
    int answer = 0;
    
    public int solution(String skill, String[] skill_trees) {
        
        for(String skill_tree : skill_trees){
            String tmp = "";
            for(int i=0;i<skill_tree.length();i++){
                String target = String.valueOf(skill_tree.charAt(i));
                if(skill.contains(target))
                    tmp += target;
            }
            for(int i=skill.length();i>=0;i--){
                String str = skill.substring(0, i);
                if(str.equals(tmp)){
                    answer++;
                    break;       
                }
            }
        }
        return answer;
    }
}