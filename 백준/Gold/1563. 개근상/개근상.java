import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        int MOD = 1_000_000;
        int[][][] dp = new int[1001][2][3];
        dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0][0] += (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][0][1] += dp[i - 1][0][0] % MOD;
            dp[i][0][2] += dp[i - 1][0][1] % MOD;
            dp[i][1][1] += dp[i - 1][1][0] % MOD;
            dp[i][1][2] += dp[i - 1][1][1] % MOD;
            for (int j = 0; j < 3; j++) {
                dp[i][1][0] += (dp[i - 1][0][j] + dp[i - 1][1][j]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                ans += dp[N][i][j];
                ans %= MOD;
            }
        }
        System.out.println(ans);
    }
}
