import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, ans;
    private static int[] arr;
    private static int[][][] dp;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[4];
        dp = new int[61][61][61];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        ans = Integer.MAX_VALUE;
        dfs(arr[0], arr[1], arr[2], 0);
        System.out.println(ans);
    }

    private static void dfs(int a, int b, int c, int cnt) {
        if (a <= 0 && b <= 0 && c <= 0) {
            ans = Math.min(ans, cnt);
            return;
        }
        a = a <= 0 ? 0 : a;
        b = b <= 0 ? 0 : b;
        c = c <= 0 ? 0 : c;
        if (0 < dp[a][b][c] && dp[a][b][c] <= cnt) {
            return;
        }
        dp[a][b][c] = cnt;
        dfs(a - 9, b - 3, c - 1, cnt + 1);
        dfs(a - 9, b - 1, c - 3, cnt + 1);
        dfs(a - 3, b - 9, c - 1, cnt + 1);
        dfs(a - 3, b - 1, c - 9, cnt + 1);
        dfs(a - 1, b - 9, c - 3, cnt + 1);
        dfs(a - 1, b - 3, c - 9, cnt + 1);
    }

}