import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, V;
    private static List<Integer>[] edge;
    private static boolean[] visited;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        edge = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            edge[A].add(B);
            edge[B].add(A);
        }
        for (int i = 1; i <= N; i++) {
            Collections.sort(edge[i]);
        }
        visited = new boolean[N + 1];
        dfs(V);
        sb.append("\n");
        visited = new boolean[N + 1];
        bfs(V);
        System.out.println(sb.toString());
    }

    private static void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(start);
        while (!q.isEmpty()) {
            int now = q.poll();
            if (visited[now]) {
                continue;
            }
            visited[now] = true;
            sb.append(now).append(" ");
            for (int i = 0; i < edge[now].size(); i++) {
                q.offer(edge[now].get(i));
            }
        }
    }

    private static void dfs(int now) {
        visited[now] = true;
        sb.append(now).append(" ");
        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now].get(i);
            if (visited[next]) {
                continue;
            }
            dfs(next);
        }
    }
}