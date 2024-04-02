import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.util.Arrays.fill;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static int[][] arr;
    private static int[][] dp;
    private static final int INF = 123456789;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][N + 1];
        dp = new int[N + 1][(1 << N) - 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
            fill(dp[i], INF);
        }
        System.out.println(dfs(0, 1));
    }

    private static int dfs(int now, int visited) {
        if (visited == (1 << N) - 1) {
            if (arr[now][0] == 0) {
                return INF;
            }
            return arr[now][0];
        }
        if (dp[now][visited] != INF) {
            return dp[now][visited];
        }
        dp[now][visited] = INF - 1;
        for (int i = 0; i < N; i++) {

            /* 방문하지 않았고 & 갈 수 있다면 */
            if ((visited & 1 << i) == 0 && arr[now][i] != 0) {
                dp[now][visited] = Math.min(dp[now][visited], dfs(i, visited | (1 << i)) + arr[now][i]);
            }
        }
        return dp[now][visited];
    }
}