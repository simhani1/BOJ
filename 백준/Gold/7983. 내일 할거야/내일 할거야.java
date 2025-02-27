import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static Queue<Work> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.t, o2.t) * -1);

    static class Work {
        int d;
        int t;

        public Work(int d, int t) {
            this.d = d;
            this.t = t;
        }
    }

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            pq.offer(new Work(d, t));
        }
        int ans = 1000000000;
        while (!pq.isEmpty()) {
            Work work = pq.poll();
            int t = work.t;
            int d = work.d;
            if (ans > t) {
                ans = t - d;
            } else {
                ans -= d;
            }
        }
        System.out.println(ans);
    }

}