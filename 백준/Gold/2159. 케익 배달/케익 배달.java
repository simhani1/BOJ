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
    static int[][] arr;
    static int[] dx = {0, 0, 0, -1, 1};
    static int[] dy = {0, -1, 1, 0, 0};
    static long[][] dp;
    static final int LEN = 100_000;
    static final long INF = 100_000_000_000L;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N][2];
        dp = new long[N][5];
        st = new StringTokenizer(br.readLine());
        int sx = Integer.parseInt(st.nextToken());
        int sy = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(0, 0, sx, sy));
    }

    private static long dfs(int depth, int type, int nowX, int nowY) {
        if (depth == N) {
            return 0;
        }
        if (dp[depth][type] != -1) {
            return dp[depth][type];
        }
        long dist = INF;
        for (int i = 0; i < 5; i++) {
            int nextX = arr[depth][0] + dx[i];
            int nextY = arr[depth][1] + dy[i];
            if (!(0 <= nextX && nextX < LEN && 0 <= nextY && nextY < LEN)) {
                continue;
            }
            dist = Math.min(dist, dfs(depth + 1, i, nextX, nextY) + getDist(nowX, nowY, nextX, nextY));
        }
        return dp[depth][type] = dist;
    }

    private static long getDist(int nowX, int nowY, int nextX, int nextY) {
        return Math.abs(nowX - nextX) + Math.abs(nowY - nextY);
    }

}