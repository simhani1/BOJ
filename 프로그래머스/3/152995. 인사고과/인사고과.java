import java.util.*;

class Solution {
    
    int answer = 1;
    boolean[] dp = new boolean[200001];
    int maxX = 0, maxY = 0;
    
    public int solution(int[][] scores) {
        int targetX = scores[0][0];
        int targetY = scores[0][1];
        Arrays.sort(scores, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                if(a[0] < b[0])
                    return 1;
                else if(a[0] == b[0]){
                    if(a[1] > b[1])
                        return 1;
                    else
                        return -1;
                }
                else
                    return -1;
            }
        });
        int sum = targetX + targetY;
        int prevPeer = 0;
        for(int[] score : scores) {
            // 동료 평가가 더 높은 경우
            if(score[1] >= prevPeer) {
                prevPeer = Math.max(prevPeer, score[1]);
                if(sum < score[0] + score[1])
                    answer++;
            }
            // 동료 평가가 낮아지는 경우 -> 태도 점수 & 동료 평가 모두 기존보다 낮은 사람으로 변경되는 시점
            else {
                if(targetX == score[0] && targetY == score[1])
                    return -1;
            }
        }
        return answer;
    }
}