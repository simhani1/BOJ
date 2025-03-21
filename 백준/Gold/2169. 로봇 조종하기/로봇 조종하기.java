import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[][] arr;
    private static int[][] dp;
    private static int[] tmpL, tmpR;
    private static int INF = -987654321;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        dp = new int[N][M];
        tmpL = new int[M];
        tmpR = new int[M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        // init
        dp[0][0] = arr[0][0];
        for (int j = 1; j < M; j++) {
            dp[0][j] = dp[0][j - 1] + arr[0][j];
        }
        for (int i = 1; i < N; i++) {
            // left -> right
            tmpL[0] = dp[i - 1][0] + arr[i][0];
            for (int j = 1; j < M; j++) {
                tmpL[j] = Math.max(tmpL[j - 1], dp[i - 1][j]) + arr[i][j];
            }
            // right -> left
            tmpR[M - 1] = dp[i - 1][M - 1] + arr[i][M - 1];
            for (int j = M - 2; j >= 0; j--) {
                tmpR[j] = Math.max(tmpR[j + 1], dp[i - 1][j]) + arr[i][j];
            }
            for (int j = 0; j < M; j++) {
                dp[i][j] = Math.max(tmpL[j], tmpR[j]);
            }
        }
        System.out.println(dp[N - 1][M - 1]);
    }

}