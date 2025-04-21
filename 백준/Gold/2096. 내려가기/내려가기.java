import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, M = 3;
    static int[][] arr, maxDp, minDp;
    static int[] dy = {-1, 0, 1};
    static final int INF = 987_654_321;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][M + 2];
        maxDp = new int[N + 1][M + 2];
        minDp = new int[N + 1][M + 2];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(solve());
    }

    private static String solve() {
        for (int i = 1; i <= N; i++) {
            Arrays.fill(minDp[i], INF);
        }
        for (int i = 1; i <= M; i++) {
            maxDp[N][i] = arr[N][i];
            minDp[N][i] = arr[N][i];
        }
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 1; j <= M; j++) {
                maxDp[i][j] = Math.max(maxDp[i][j], getMaxOf(i, j) + arr[i][j]);
                minDp[i][j] = Math.min(minDp[i][j], getMinOf(i, j) + arr[i][j]);
            }
        }
        int maxAns = 0, minAns = INF;
        for (int j = 1; j <= M; j++) {
            maxAns = Math.max(maxAns, maxDp[1][j]);
            minAns = Math.min(minAns, minDp[1][j]);
        }
        return sb.append(maxAns).append(" ").append(minAns).toString();
    }

    private static int getMaxOf(int i, int j) {
        return Math.max(maxDp[i + 1][j], Math.max(maxDp[i + 1][j - 1], maxDp[i + 1][j + 1]));
    }

    private static int getMinOf(int i, int j) {
        return Math.min(minDp[i + 1][j], Math.min(minDp[i + 1][j - 1], minDp[i + 1][j + 1]));
    }
}