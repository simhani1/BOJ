import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, ans = Integer.MAX_VALUE;
    private static int[][] arr = new int[11][2];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        solve(0, 0);
        System.out.println(ans);
    }

    private static void solve(int flag, int idx) {
        if (idx == N) {
            int A = 1;
            int B = 0;
            if (flag == 0) {
                return;
            }
            for (int i = 0; i < N; i++) {
                if ((flag & (1 << i)) > 0) {
                    A *= arr[i][0];
                    B += arr[i][1];
                }
            }
            ans = Math.min(ans, Math.abs(A - B));
            return;
        }
        solve(flag, idx + 1);
        flag |= (1 << idx);
        solve(flag, idx + 1);
    }
}