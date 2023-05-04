import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < bridge_length; i++) {
            q.offer(0);
        }
        int answer = 0, sum = 0, idx = 0;
        while (idx < truck_weights.length) {
            sum -= q.poll();
            answer++;
            if (sum + truck_weights[idx] <= weight) {
                q.offer(truck_weights[idx]);
                sum += truck_weights[idx];
                idx++;
            } else {
                q.offer(0);
            }
        }
        System.out.println(answer + bridge_length);
        return answer + bridge_length;
    }
}