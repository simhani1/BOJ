import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, R, Q;
    private static int[] arr = new int[100001];
    private static int[] dp = new int[100001];
    private static List<Node>[] tree = new ArrayList[100001];

    static class Node {
        int to;

        public Node(int to) {
            this.to = to;
        }
    }

    public static void main(String[] args) throws Exception {
        /* input */
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        /* init */
        for (int i = 0; i <= N; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(new Node(v));
            tree[v].add(new Node(u));
        }
        /* set level */
        dfs(R, 1);
        /* query */
        while (Q-- > 0) {
            int u = Integer.parseInt(br.readLine());
            sb.append(dp[u]).append("\n");
        }
        System.out.println(sb);
    }

    private static int dfs(int now, int level) {
        arr[now] = level;
        int sum = 1;
        for (Node node : tree[now]) {
            if (arr[node.to] == 0) {
                sum += dfs(node.to, level + 1);
            }
        }
        return dp[now] = sum;
    }

}