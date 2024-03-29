import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.util.Arrays.fill;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, K;
    private static int[] arr = new int[100001];
    private static int[][] dp = new int[100001][2];

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        /* 총합이 음수, 0, 양수 모두 가능하므로 음수로 초기화 */
        for (int i = 0; i <= N; i++) {
            fill(dp[i], -123456789);
        }
        int ans = Integer.MIN_VALUE;
         /* 수를 제거하지 않는 경우 */
        for (int i = 1; i <= N; i++) {
            dp[i][0] = arr[i];
            if (dp[i - 1][0] + arr[i] > dp[i][0]) {
                dp[i][0] = dp[i - 1][0] + arr[i];
            }
        }
        /* 이전 수를 제거한 경우 VS 제거하지 않은 경우 */
        for (int i = 2; i <= N; i++) {
            dp[i][1] = Math.max(dp[i - 2][0], dp[i - 1][1]) + arr[i];
        }
        /* 정답 */
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 2; j++) {
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans);
    }
}