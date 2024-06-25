import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static final long INF = Long.MAX_VALUE;
    private static int maxDist, N;
    private static int[] dist;
    private static long[] dp;
    private static int[] time;
    private static int[] parent;

    public static void main(String[] args) throws IOException {
        maxDist = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        dist = new int[N + 2];
        dp = new long[N + 2];
        time = new int[N + 2];
        parent = new int[N + 2];
        for (int i = 1; i <= N + 1; i++) {
            dist[i] = Integer.parseInt(st.nextToken()) + dist[i - 1];
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            time[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 1; i <= N + 1; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dist[i] - dist[j] > maxDist) {
                    break;
                }
                if (dp[i] > dp[j] + time[j]) {
                    dp[i] = dp[j] + time[j];
                    parent[i] = j;
                }
            }
        }
        String history = "";
        int num = parent[N + 1];
        int cnt = 0;
        while (num != 0) {
            history = num + " " + history;
            num = parent[num];
            cnt++;
        }
        System.out.println(dp[N + 1]);
        System.out.println(cnt);
        System.out.println(history);
    }

}