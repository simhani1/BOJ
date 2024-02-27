import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[][] arr;
    private static int[][] dp;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][3];
        dp = new int[N + 1][3];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            arr[i][2] = Integer.parseInt(st.nextToken());
        }
        
        int ans = 123456789;
        
        init();
        dp[0][0] = arr[0][0];
        for (int i = 1; i < N - 1; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }
        dp[N - 1][1] = Math.min(dp[N - 2][0], dp[N - 2][2]) + arr[N - 1][1];
        dp[N - 1][2] = Math.min(dp[N - 2][0], dp[N - 2][1]) + arr[N - 1][2];
        ans = findMinValue(ans);

        init();
        dp[0][1] = arr[0][1];
        for (int i = 1; i < N - 1; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }
        dp[N - 1][0] = Math.min(dp[N - 2][1], dp[N - 2][2]) + arr[N - 1][0];
        dp[N - 1][2] = Math.min(dp[N - 2][0], dp[N - 2][1]) + arr[N - 1][2];
        ans = findMinValue(ans);

        init();
        dp[0][2] = arr[0][2];
        for (int i = 1; i < N - 1; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }
        dp[N - 1][0] = Math.min(dp[N - 2][1], dp[N - 2][2]) + arr[N - 1][0];
        dp[N - 1][1] = Math.min(dp[N - 2][0], dp[N - 2][2]) + arr[N - 1][1];
        ans = findMinValue(ans);
        System.out.println(ans);
    }

    private static int findMinValue(int ans) {
        for (int i = 0; i < 3; i++) {
            ans = Math.min(ans, dp[N - 1][i]);
        }
        return ans;
    }

    private static void init() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = 123456789;
            }
        }
    }
}