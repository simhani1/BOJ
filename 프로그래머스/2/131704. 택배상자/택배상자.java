import java.util.*;

class Solution {

    Stack<Integer> st = new Stack<>();
    
    public int solution(int[] order) {
        int answer = 0;
        int idx = 0;
        for(int now=1;now<=order.length;now++){
            if(order[idx] != now){
                st.push(now);
                continue;
            }
            idx++;
            answer++;
            while(!st.isEmpty() && st.peek() == order[idx]){
                st.pop();
                idx++;
                answer++;
            }
        }
        return answer;
    }
}