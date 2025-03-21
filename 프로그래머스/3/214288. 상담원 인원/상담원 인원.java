import java.util.*;

class Solution {
    
    int N, K, ans;
    int[][] arr;
    int[] selected;
    public int solution(int k, int n, int[][] reqs) {
        int answer = 0;
        K = k;
        N = n;
        // i번 유형마다 j명 상담원이 있을때 각 유형의 상담을 모두 해결할 때의 대기시간
        arr = new int[K + 1][N - K + 2];
        selected = new int[K + 1];
        for (int i = 1; i <= K; i++) {
            calcTime(i, reqs);
        }
        // 자연수 분할
        ans = Integer.MAX_VALUE;
        dfs(1, 0);
        return ans;
    }
    
    private void dfs(int idx, int sum) { 
        if (idx == K + 1) {
            if (sum == N) {
                int result = 0;
                for (int i = 1; i <= K; i++) {
                    result += arr[i][selected[i]];
                }
                ans = Math.min(ans, result);
            }
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (sum + i <= N) {
                selected[idx] = i;
                dfs(idx + 1, sum + i);
            }
        }
    }
    
    private void calcTime(int nowType, int[][] reqs) {
        // 가능한 모든 상담원 수마다 모든 상담을 끝냈을 때의 총 대기시간
        for (int i = 1; i <= N - K + 1; i++) {
            Queue<Integer> pq = new PriorityQueue<>();
            int waitingTime = 0;
            for (int j = 0; j < reqs.length; j++) {
                int start = reqs[j][0];
                int end = reqs[j][1];
                int type = reqs[j][2];
                if (type != nowType) {
                    continue;
                }
                // 상담원이 놀고 있는 경우
                if (pq.size() < i) {
                    pq.offer(start + end);
                }
                // 상담원이 모두 일하고 있는 경우
                else {
                    int possibleTime = pq.poll();
                    // 앞선 상담이 현재 상담보다 일찍 끝나는 경우
                    if (possibleTime <= start) {
                        pq.offer(start + end);
                    }
                    else {
                        pq.offer(possibleTime + end);   
                        waitingTime += possibleTime - start;  // 대기시간 발생
                    }
                } 
            }
            arr[nowType][i] = waitingTime;
        }
    }

}