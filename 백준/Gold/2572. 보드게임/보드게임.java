import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K, ans;
    private static char[] card;
    private static int[][] dp;
    private static List<Edge>[] edgeList;
    private static final int INF = 123456789;

    static class Edge {
        int to;
        char color;

        public Edge(int to, char color) {
            this.to = to;
            this.color = color;
        }

        @Override
        public String toString() {
            return "Edge{" +
                    "to=" + to +
                    ", color=" + color +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        card = new char[N + 1];
        ans = 0;
        for (int i = 1; i <= N; i++) {
            card[i] = st.nextToken().charAt(0);
        }
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dp = new int[M + 1][N + 1];
        edgeList = new ArrayList[M + 1];
        for (int i = 0; i <= M; i++) {
            edgeList[i] = new ArrayList<>();
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            char color = st.nextToken().charAt(0);
            edgeList[from].add(new Edge(to, color));
            edgeList[to].add(new Edge(from, color));
        }
        System.out.println(dfs(1, 1));
    }

    private static int dfs(int now, int idx) {
        if (idx == N + 1) {
            return 0;
        }
        if (dp[now][idx] != -1) {
            return dp[now][idx];
        }
        dp[now][idx] = 0;
        for (int i = 0; i < edgeList[now].size(); i++) {
            Edge edge = edgeList[now].get(i);
            int next = edge.to;
            char color = edge.color;
            dp[now][idx] = Math.max(dp[now][idx], dfs(next, idx + 1) + (card[idx] == color ? 10 : 0));
        }
        return dp[now][idx];
    }
}