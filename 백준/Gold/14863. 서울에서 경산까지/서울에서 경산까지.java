import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[][] arr = new int[N + 1][4];
        for (int i = 1; i <= N; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < str.length; j++) {
                arr[i][j] = Integer.parseInt(str[j]);
            }
        }
        System.out.println(solve(N, K, arr));
    }

    private static int solve(int N, int K, int[][] arr) {
        int ans = 0;
        int[][] dp = new int[N + 1][K + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = -1;
            }
        }
        // init
        /*
        첫 도시를 가는데 걸리는 시간이 동일한 경우 예외 처리
        2 4
        2 5 2 2
        2 2 2 2
        */
        if (arr[1][0] == arr[1][2]) {
            dp[1][arr[1][0]] = Math.max(arr[1][1], arr[1][3]);
        } else {
            dp[1][arr[1][2]] = arr[1][3];
            dp[1][arr[1][0]] = arr[1][1];
        }
        // solve
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                if (dp[i - 1][j] == -1)
                    continue;
                if (j + arr[i][0] <= K) {
                    dp[i][j + arr[i][0]] = Math.max(dp[i][j + arr[i][0]], dp[i - 1][j] + arr[i][1]);
                }
                if (j + arr[i][2] <= K) {
                    dp[i][j + arr[i][2]] = Math.max(dp[i][j + arr[i][2]], dp[i - 1][j] + arr[i][3]);
                }
            }
        }
        for (int i = 0; i <= K; i++) {
            ans = Math.max(ans, dp[N][i]);
        }
        return ans;
    }
}

