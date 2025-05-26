import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static PriorityQueue<Taxi> pq = new PriorityQueue<>();

    static class Taxi implements Comparable<Taxi> {
        int start;
        int end;

        public Taxi(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public String toString() {
            return "Taxi{" +
                "start=" + start +
                ", end=" + end +
                '}';
        }

        @Override
        public int compareTo(Taxi o) {
            if (this.end == o.end) {
                return Integer.compare(this.start, o.start) * -1;
            }
            return Integer.compare(this.end, o.end);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            if (start <= end) continue;
            pq.offer(new Taxi(start, end));
        }
        long ans = M;
        while (!pq.isEmpty()) {
            Taxi now = pq.poll();
            while (!pq.isEmpty() && pq.peek().end <= now.start) {
                now.start = Math.max(now.start, pq.poll().start);
            }
            ans += Math.abs(now.end - now.start) * 2L;
        }
        System.out.println(ans);
    }
}
