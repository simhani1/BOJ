import java.util.*;

class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        // 1 2 3 1
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<ingredient.length;i++){
            st.push(ingredient[i]);
            if(st.size() >= 4){
                int lastIdx = st.size() - 1;
                if(st.get(lastIdx) == 1 && st.get(lastIdx -1) == 3 && st.get(lastIdx - 2) == 2 && st.get(lastIdx - 3) == 1){
                    answer++;
                    for(int j=0;j<4;j++){
                        st.pop();      
                    }
                }
            }
        }
        return answer;
    }
}