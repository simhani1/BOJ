import java.util.*;

class Solution {
    
    private PriorityQueue<Server> q = new PriorityQueue<>((o1, o2) -> {
        return Integer.compare(o1.startedAt, o2.startedAt);
    });
    
    class Server {
        int startedAt;
        int finishedAt;
        
        public Server (int startedAt, int finishedAt) {
            this.startedAt = startedAt;
            this.finishedAt = finishedAt;
        }
    }
    
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        for (int i = 0; i < 24; i++) {
            int player = players[i];
            /* 서버 반납 */
            while(!q.isEmpty() && i >= q.peek().finishedAt) {
                q.poll();
            }
            /* 서버 증설 */
            int minServerCnt = player / m;
            int addCnt = minServerCnt - q.size();
            for (int j = 0; j < addCnt; j++) {
                q.offer(new Server(i, i + k));
                answer++;
            }
        }
        return answer;
    }
}