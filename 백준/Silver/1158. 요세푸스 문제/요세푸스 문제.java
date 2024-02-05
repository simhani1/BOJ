import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, K;
    private static Deque<Integer> dq = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            dq.offerLast(i);
        }
        solve();

        System.out.println(sb.toString());
    }

    private static void solve() {
        sb.append("<");
        while (!dq.isEmpty()) {
            for (int i = 0; i < K - 1; i++) {
                dq.offerLast(dq.removeFirst());
            }
            sb.append(dq.removeFirst());
            if (!dq.isEmpty()) {
                sb.append(", ");
            }
        }
        sb.append(">");
    }
}