import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] dp = new int[M + 1][N + 1];
        int[][] arr = new int[M + 1][2];
        for (int i = 1; i <= M; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st2.nextToken());
            int B = Integer.parseInt(st2.nextToken());
            arr[i][0] = A;
            arr[i][1] = B;
        }
        // solution
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (j - arr[i][0] >= 0) {
                    dp[i][j] = Math.max(dp[i - 1][j - arr[i][0]] + arr[i][1], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[M][N]);
    }
}