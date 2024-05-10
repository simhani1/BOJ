import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, A, B, ans;
    private static List<Node>[] edge;
    private static boolean[] visited;

    static class Node {
        int to;
        int dist;

        public Node(int to, int dist) {
            this.to = to;
            this.dist = dist;
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        edge = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            edge[from].add(new Node(to, dist));
            edge[to].add(new Node(from, dist));
        }
        dfs(A, 0, 0);
        System.out.println(ans);
    }

    private static void dfs(int now, int sum, int maxDist) {
        visited[now] = true;
        /* 다른 로봇까지 도달한 경우 */
        if (now == B) {
            ans = sum - maxDist;
            return;
        }
        for (int i = 0; i < edge[now].size(); i++) {
            Node node = edge[now].get(i);
            int next = node.to;
            int dist = node.dist;
            if (!visited[next]) {
                dfs(next, sum + dist, Math.max(maxDist, dist));
            }
        }
    }
}