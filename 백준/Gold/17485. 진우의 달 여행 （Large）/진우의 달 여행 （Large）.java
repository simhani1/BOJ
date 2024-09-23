import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[][] arr;
    private static int[][][] dp;
    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dp = new int[N + 1][M + 1][3];
        arr = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        /* init */
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 3; k++) {
                dp[1][j][k] = arr[1][j];
            }
        }
        /* solve */
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (j == 1) {
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]);
                    dp[i][j][2] = arr[i][j] + Math.min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
                } else if (j == M) {
                    dp[i][j][0] = arr[i][j] + Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]);
                } else {
                    dp[i][j][0] = arr[i][j] + Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]);
                    dp[i][j][2] = arr[i][j] + Math.min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
                }
            }
        }
        int ans = INF;
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 3; k++) {
                ans = Math.min(ans, dp[N][j][k]);
            }
        }
        System.out.println(ans);
    }

}