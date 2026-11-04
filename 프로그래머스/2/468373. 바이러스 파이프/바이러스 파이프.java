import java.util.*;


class Edge {
    int to, type;
    public Edge(int to, int type) {
        this.to = to;
        this.type = type;
    }
}

class Solution {
    
    int N, infection, K, answer = 0;
    List<Edge>[] graph;
    
    public int solution(int n, int infection, int[][] edges, int k) {
        this.N = n;
        this.infection = infection;
        this.K = k;
        this.graph = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(new Edge(edge[1], edge[2]));
            graph[edge[1]].add(new Edge(edge[0], edge[2]));
        }
        
        comb(new ArrayList<>(), 0);
        return answer;
    }
    
    void comb(List<Integer> list, int depth) {
        if (depth == K) {
            bfs(list);
            return;
        }
        for (int i = 1; i <= 3; i++) {
            list.add(i);
            comb(list, depth + 1);
            list.remove(list.size() - 1);
        }
    }
    
    void bfs(List<Integer> list) {
        boolean[] visited = new boolean[N + 1];
        visited[infection] = true;
        int cnt = 1;
        
        for (int gate : list) {
            Queue<Integer> q = new ArrayDeque<>();
            
            for (int i = 1; i <= N; i++) {
                if (visited[i]) {
                    q.offer(i);
                }
            }
            
            while (!q.isEmpty()) {
                int now = q.poll();
                
                for (Edge edge : graph[now]) {
                    if (edge.type != gate) {
                        continue;
                    }
                    if (visited[edge.to]) {
                        continue;
                    }
                    visited[edge.to] = true;
                    q.offer(edge.to);
                    cnt++;
                }
            }
            answer = Math.max(answer, cnt);
        }
    }
}