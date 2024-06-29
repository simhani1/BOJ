import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static int[] arr;
    private static int[][][] dp;

    public static void main(String[] args) throws IOException {
        arr = new int[100001];
        dp = new int[100001][5][5];
        input();
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        System.out.println(dfs(0, 0, 0));
    }

    private static int dfs(int left, int right, int idx) {
        if (idx == N) {
            return 0;
        }
        if (dp[idx][left][right] != -1) {
            return dp[idx][left][right];
        }
        dp[idx][left][right] = Math.min(dfs(arr[idx], right, idx + 1) + calcPower(left, arr[idx]),
            dfs(left, arr[idx], idx + 1) + calcPower(right, arr[idx]));
        return dp[idx][left][right];
    }

    private static int calcPower(int now, int next) {
        if (now == next) {
            return 1;
        } else if (now == 0) {
            return 2;
        } else if (Math.abs(now - next) == 1 || Math.abs(now - next) == 3) {
            return 3;
        } else {
            return 4;
        }
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = 0;
        while (true) {
            int num = Integer.parseInt(st.nextToken());
            if (num == 0) {
                return;
            }
            arr[N++] = num;
        }
    }

}