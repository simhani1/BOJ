import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N;
    private static PriorityQueue<Long> pq;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        pq = new PriorityQueue<>();
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                pq.offer(Long.parseLong(st.nextToken()));
            }
            long ans = 0;
            while (pq.size() != 1) {
                long num1 = pq.poll();
                long num2 = pq.poll();
                ans += num1 + num2;
                pq.offer(num1 + num2);
            }
            pq.poll();
            sb.append(ans).append("\n");
        }
        System.out.println(sb);
    }

}