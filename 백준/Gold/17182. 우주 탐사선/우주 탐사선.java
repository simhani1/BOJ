import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, K, ans;
    private static int[][] arr;
    private static final int INF = 123456789;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        floyd();
        ans = INF;
        solve(K, 0, 1 << K);
        System.out.println(ans);
    }

    private static void floyd() {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }

    private static void solve(int now, int cost, int bit) {
        if (bit == (1 << N) - 1) {
            ans = Math.min(ans, cost);
            return;
        }
        for (int j = 0; j < N; j++) {
            if ((bit & 1 << j) == 0) {
                solve(j, cost + arr[now][j], bit | 1 << j);
            }
        }
    }
}