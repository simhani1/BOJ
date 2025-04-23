import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(1, 0, N - 1));
    }

    private static int dfs(int k, int l, int r) {
        if (l == r) {
            return k * arr[l];
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int cost = 0;
        cost = Math.max(cost, k * arr[r] + dfs(k + 1, l, r - 1));
        cost = Math.max(cost, k * arr[l] + dfs(k + 1, l + 1, r));
        return dp[l][r] = cost;
    }
}