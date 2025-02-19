import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, H;
    private static int[][] arr;
    private static int[][] dp;
    private static int MOD = 10007;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M];
        dp = new int[N + 1][H + 1];
        for (int i = 1; i <= N; i++) {
            String[] s = br.readLine().split(" ");
            for (int j = 0; j < s.length; j++) {
                arr[i][j] = Integer.parseInt(s[j]);
            }
            dp[i][0] = 1;
        }
        /* init */
        for (int i = 0; i < M; i++) {
            dp[1][arr[1][i]]++;
        }
        /* solve */
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= H; j++) {
                dp[i][j] += dp[i - 1][j];
                for (int k = 0; k < M; k++) {
                    if (arr[i][k] == 0) {
                        break;
                    }
                    int diff = j - arr[i][k];
                    if (diff >= 0) {
                        dp[i][j] += dp[i - 1][diff];
                    }
                }
                dp[i][j] %= MOD;
            }
        }
        System.out.println(dp[N][H]);
    }
}