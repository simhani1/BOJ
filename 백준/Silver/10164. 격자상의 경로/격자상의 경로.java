import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K, ans;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dp = new int[N + 1][M + 1];
        ans = 0;
        if (K == 0) {
            ans = solve(N, M);
        } else {
            int stopOverX = (K - 1) / M + 1;
            int stopOverY = K - (stopOverX - 1) * M;
            ans = solve(stopOverX, stopOverY) * solve(N - stopOverX + 1, M - stopOverY + 1);
        }
        System.out.println(ans);
    }

    private static int solve(int gx, int gy) {
        dp[1][1] = 1;
        for (int i = 1; i <= gx; i++) {
            for (int j = 1; j <= gy; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[gx][gy];
    }
}