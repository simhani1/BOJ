import java.util.*;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0;i<score.length;i++){
            int target = score[i];
            pq.add(target);
            // k명이 되기 전
            if(pq.size() <= k){
                answer[i] = pq.peek();
            }
            // k명이 넘어간 경우
            else{
                pq.poll();
                answer[i] = pq.peek();
            }
        }
        return answer;
        
    }
}