import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[] arr;
    private static int[] dp;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        dp = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            int max = 0;
            int min = Integer.MAX_VALUE;
            for (int j = i; j >= 1; j--) {
                max = Math.max(max, arr[j]);
                min = Math.min(min, arr[j]);
                dp[i] = Math.max(dp[i], max - min + dp[j - 1]);
            }
        }
        System.out.println(dp[N]);
    }

}