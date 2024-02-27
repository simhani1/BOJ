import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[] dp;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        /* i를 만드는데 필요한 최소 연산 횟수 */
        dp = new int[N + 1];
        Arrays.fill(dp, 123456789);
        dp[N] = 0;
        for (int i = N; i >= 1; i--) {
            if (i % 3 == 0) {
                dp[i / 3] = Math.min(dp[i / 3], dp[i] + 1);
            }
            if (i % 2 == 0) {
                dp[i / 2] = Math.min(dp[i / 2], dp[i] + 1);
            }
            dp[i - 1] = Math.min(dp[i - 1], dp[i] + 1);
        }
        System.out.println(dp[1]);
    }
}