import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, T;
    private static Deque<Integer> dq;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            dq = new ArrayDeque<>();
            T = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 8; i++) {
                dq.addLast(Integer.parseInt(st.nextToken()));
            }
            sb.append("#")
                    .append(t)
                    .append(" ");
            solve();
        }
        System.out.println(sb.toString());
    }

    private static void solve() {
        int diff = 1;
        while (true) {
            int num = dq.pollFirst();
            num -= diff;
            if (num <= 0) {
                dq.addLast(0);
                break;
            }
            dq.addLast(num);
            diff = (diff == 5) ? 1 : diff + 1;
        }
        for (int i = 0; i < 8; i++) {
            sb.append(dq.pollFirst())
                    .append(" ");
        }
        sb.append("\n");
    }
}