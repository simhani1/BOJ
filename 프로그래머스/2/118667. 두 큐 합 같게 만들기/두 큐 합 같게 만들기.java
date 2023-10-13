import java.util.*;

class Solution {
    
    Queue<Long> q1 = new LinkedList<>();
    Queue<Long> q2 = new LinkedList<>();
    long sum1 = 0, sum2 = 0;
    
    public long solution(int[] queue1, int[] queue2) {
        long answer = 0;
        long sum = 0;
        for(int i=0;i<queue1.length;i++){
            q1.add((long) queue1[i]);
            q2.add((long) queue2[i]);
            sum += (queue1[i] + queue2[i]);
            sum1 += queue1[i];
            sum2 += queue2[i];
        }
        // 합이 홀수
        if(sum % 2 == 1)
            return -1;
        int cnt = 0;
        while(sum1 != sum2){
            if(sum1 == 0 || sum2 == 0)
                return -1;
            if(cnt > 3 * queue1.length)
                return -1;
            if(sum1 > sum2){
                if(q1.isEmpty())
                    return -1;
                sum1 -= q1.peek();
                sum2 += q1.peek();
                q2.add(q1.peek());
                q1.remove();      
            }
            else{
                if(q2.isEmpty())
                    return -1;
                sum2 -= q2.peek();
                sum1 += q2.peek();
                q1.add(q2.peek());
                q2.remove();                
            }
            cnt++;
            answer++;
        }
        return answer;
    }
}