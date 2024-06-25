import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        System.out.println(solve());
    }

    private static long solve() {
        long ans = Long.MAX_VALUE;
        long l = 1, r = 1000000000L * M;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (isPossible(mid)) {
                ans = Math.min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    private static boolean isPossible(long target) {
        long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (target / (long) arr[i]);
            if (M <= cnt) {
                return true;
            }
        }
        return false;
    }

}