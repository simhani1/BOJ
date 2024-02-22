import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, start, ans;
    private static boolean[][] checked;
    private static int[] visited;

    public static void main(String[] args) throws Exception {
        for (int t = 1; t <= 10; t++) {
            sb.append("#").append(t).append(" ");
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(st.nextToken());
            checked = new boolean[101][101];
            visited = new int[101];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N / 2; i++) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                if (!checked[from][to]) {
                    checked[from][to] = true;
                }
            }
            ans = 0;
            int maxDepth = bfs(start);
            for (int i = 100; i >= 1; i--) {
                if (visited[i] == maxDepth) {
                    ans = i;
                    break;
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int bfs(int s) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(s);
        visited[s] = 1;
        int maxDepth = 1;
        while (!q.isEmpty()) {
            int now = q.poll();
            for (int next = 1; next <= 100; next++) {
                if (checked[now][next] && visited[next] == 0) {
                    q.offer(next);
                    visited[next] = visited[now] + 1;
                }
            }
            maxDepth = Math.max(maxDepth, visited[now]);
        }
        return maxDepth;
    }
}