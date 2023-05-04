import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        Queue<Integer> q = new LinkedList<>();
        
        for(int i : priorities) {
            pq.offer(i);
        }
        for(int i=0;i<priorities.length;i++){
            q.offer(i);
        }
        

        while(!q.isEmpty()){
            int originalIdx = q.poll();
            int originalValue = priorities[originalIdx];
            int maxValue = pq.peek();
            if(originalValue < maxValue){
                q.offer(originalIdx);
            }
            else if(originalValue == maxValue){
                if(originalIdx == location){
                    return answer;
                }
                else{
                    pq.poll();
                    answer++;
                }
            }
        }
        
        return answer;
    }
}