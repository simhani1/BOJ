import javax.management.MBeanRegistration;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.concurrent.atomic.AtomicReference;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[] w, c;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        w = new int[N + 1];
        c = new int[N + 1];
        dp = new int[N + 1][10001];
        for (int i = 1; i <= N; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            c[i] = Integer.parseInt(st.nextToken());
        }
        /* init */
        for (int i = 0; i <= 10000; i++) {
            if (i >= c[1]) {
                dp[1][i] = w[1];
            }
        }
        /* 냅색 */
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 10000; j++) {
                if (c[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
                }
            }
        }
        for (int i = 0; i <= 10000; i++) {
            if (dp[N][i] >= M) {
                System.out.println(i);
                break;
            }
        }
    }
}