import java.util.*;

class Solution {
    
    private List<Integer>[] edge;
    private int[] dist;
    private final int INF = Integer.MAX_VALUE;
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        
        edge = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            edge[i] = new ArrayList<>();
        }
        dist = new int[n + 1];
        Arrays.fill(dist, INF);
        
        for (int i = 0; i < roads.length; i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            edge[a].add(b);
            edge[b].add(a);
        }
        
        
        bfs(sources[0], destination);
        
        return answer;
    }
    
    private int bfs(int source, int destination) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(source);
        while(!q.isEmpty()) {
            int now = q.poll();
            if (now == destination) {
                break;
            }
            for (int next : edge[now]) {
                if (dist[next] == INF) {
                    dist[next] = dist[now] + 1;
                    q.offer(next);
                }
            }
        }
        return -1;
    }
}