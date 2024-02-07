import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, X;
    private static PriorityQueue<Num> pq = new PriorityQueue<>((o1, o2) -> {
        if (o1.abs == o2.abs) {
            return Integer.compare(o1.origin, o2.origin);
        }
        return Integer.compare(o1.abs, o2.abs);
    });

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            X = Integer.parseInt(br.readLine());
            if (X != 0) {
                pq.offer(new Num(X, Math.abs(X)));
            } else {
                if (pq.isEmpty()) {
                    sb.append("0\n");
                } else {
                    Num num = pq.poll();
                    sb.append(num.origin).append("\n");
                }
            }
        }
        System.out.println(sb.toString());
    }
}

class Num {
    int origin;
    int abs;

    public Num(int origin, int abs) {
        this.origin = origin;
        this.abs = abs;
    }
}