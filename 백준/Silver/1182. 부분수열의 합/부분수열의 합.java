import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, S, ans;
    private static int[] arr = new int[21];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        ans = 0;
        solve(0, 0);
        System.out.println(ans);
    }

    private static void solve(int flag, int cnt) {
        if (cnt == N) {
            if (flag == 0) {
                return;
            }
            int sum = 0;
            for (int i = 0; i < N; i++) {
                if (((1 << i) & flag) > 0) {
                    sum += arr[i];
                }
            }
            if (sum == S) {
                ans++;
            }
            return;
        }
        solve(flag, cnt + 1);
        flag |= (1 << cnt);
        solve(flag, cnt + 1);
    }
}