import java.util.*;

class Solution {
    final int MAX = 100_000;
    int  N;
    List<Integer>[] graph;
    boolean[] visited, light;
    
    public int solution(int n, int[][] lighthouse) {
        this.N = n;
        visited = new boolean[MAX + 1];
        light = new boolean[MAX + 1];
        graph = new ArrayList[MAX + 1];
        for (int i = 0; i <= MAX; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : lighthouse) {
            int a = edge[0];
            int b = edge[1];
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs(1, 1);
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (light[i]) {
                answer++; 
            }
        }
        return answer;
    }
    
    private void dfs(int now, int parent) {
        visited[now] = true;
        for (int next : graph[now]) {
            if (!visited[next]) {
                dfs(next, now);
            }
        }
        // 자식 중 하나라도 등대가 꺼져있다면, 현재 노드는 등대를 켜야 함
        for (int child : graph[now]) {
            if (child == parent) {
                continue;
            }
            if (!light[child]) {
                light[now] = true;
                break;
            }
        }
    }
}