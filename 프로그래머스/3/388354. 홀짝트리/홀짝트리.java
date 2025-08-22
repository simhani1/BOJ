import java.util.*;

class Solution {

    final int MAX = 1_000_000;
    int[] nodes; 
    int[][] edges;
    List<Integer>[] graph;
    Set<Integer> visited;
    int yCnt = 0;
    int rCnt = 0;
    
    public int[] solution(int[] nodes, int[][] edges) {
        this.nodes = nodes;
        this.edges = edges;
        visited = new HashSet<>();
        graph = new ArrayList[MAX + 1];
        for (int i = 0; i <= MAX; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].add(b);
            graph[b].add(a);
        }
        int[] answer = new int[2];
        for (int root : nodes) {  
            yCnt = rCnt = 0; 
            dfs(root);
            if (yCnt == 1) {
                answer[1]++;
            }
            if (rCnt == 1) {
                answer[0]++;
            }
        }
        return answer;
    }
    
    private void dfs(int now) {
        if (visited.contains(now)) {
            return;
        }
        visited.add(now);
        if (now % 2 == (graph[now].size() - 1)% 2) {
            yCnt++;
        } else {
            rCnt++;
        }
        for (int next : graph[now]) {
            dfs(next);
        }
    }
}