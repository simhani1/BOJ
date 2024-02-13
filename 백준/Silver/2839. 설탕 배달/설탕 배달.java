import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.util.Arrays.fill;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[] dp = new int[5001];
    private static final int INF = 12345;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        fill(dp, INF);
        dp[3] = 1;
        dp[5] = 1;
        for (int i = 6; i <= 5000; i++) {
            dp[i] = Math.min(dp[i - 3] + 1, dp[i - 5] + 1);
        }
        System.out.println(dp[N] >= INF ? -1 : dp[N]);
    }
}