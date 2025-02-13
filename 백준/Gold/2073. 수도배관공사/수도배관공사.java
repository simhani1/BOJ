import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int D, P;
    private static int[] dp;
    private static int[][] arr;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        D = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        dp = new int[D + 1];
        arr = new int[P + 1][2];
        dp[0] = Integer.MAX_VALUE;
        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            for (int j = D; j >= 0; j--) {
                if (j - arr[i][0] >= 0) {
                    dp[j] = Math.max(dp[j], Math.min(dp[j - arr[i][0]], arr[i][1]));
                }
            }
        }
        System.out.println(dp[D]);
    }
}