import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;

    private static int T, N, M, K;
    private static int[] arr, home;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            arr = new int[N + 1];
            home = new int[N + M + 1];
            for (int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                home[i] = arr[i];
            }
            for (int i = 1; i < M; i++) {
                home[i + N] = arr[i];
            }
            int pSum = 0, ans = 0;
            /* init */
            int l = 0, r = l + M;
            for (int i = l; i <= r; i++) {
                pSum += home[i];
            }
            if (N == M && pSum < K) {
                ans++;
            } else if (N != M) {
                /* solve */
                while (l <= N && r < N + M) {
                    if (pSum < K) {
                        ans++;
                    }
                    pSum -= home[++l];
                    pSum += home[++r];
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.println(sb);
    }
}