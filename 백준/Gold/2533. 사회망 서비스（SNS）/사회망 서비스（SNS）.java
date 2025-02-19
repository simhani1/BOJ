import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static List<Integer>[] edge;
    private static boolean[] visited;
    private static int[][] dp;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        visited = new boolean[N + 1];
        dp = new int[N + 1][2];
        edge = new List[N + 1];
        for (int i = 0; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edge[u].add(v);
            edge[v].add(u);
        }
        dfs(1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }

    private static void dfs(int now) {
        visited[now] = true;
        dp[now][0] = 1;
        dp[now][1] = 0;
        for (int next : edge[now]) {
            if (!visited[next]) {
                dfs(next);
                dp[now][0] += Math.min(dp[next][0], dp[next][1]);
                dp[now][1] += dp[next][0];
            }
        }
    }
}