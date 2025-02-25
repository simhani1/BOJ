import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[] arr;
    private static int[] dp;

    public static void main(String[] args) throws Exception {
        /* input */
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        /* solve */
        dp[0] = arr[0];
        int len = 1;
        for (int i = 0; i < N; i++) {
            int now = arr[i];
            if (dp[len - 1] < now) {
                dp[len++] = now;
            } else {
                int idx = findIdx(0, len - 1, now);
                dp[idx] = now;
            }
        }
        System.out.println(N - len);
    }

    private static int findIdx(int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dp[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

}