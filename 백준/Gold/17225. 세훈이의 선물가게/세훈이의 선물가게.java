import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int A, B, N;
    static int aTime, bTime;
    static Queue<Job> pq = new PriorityQueue<>((o1, o2) -> {
        if (o1.time == o2.time) {
            return Character.compare(o1.color, o2.color);
        }
        return Integer.compare(o1.time, o2.time);
    });
    static Queue<Integer> aAnsQ = new ArrayDeque<>();
    static Queue<Integer> bAnsQ = new ArrayDeque<>();

    static class Job {
        int time;
        char color;

        public Job(int time, char color) {
            this.time = time;
            this.color = color;
        }

        @Override
        public String toString() {
            return "Job{" +
                "time=" + time +
                ", color=" + color +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        aTime = bTime = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);
            int m = Integer.parseInt(st.nextToken());
            for (int j = 0; j < m; j++) {
                if (c == 'B') {
                    aTime = addJob(aTime, t, c, A);
                } else{
                    bTime = addJob(bTime, t, c, B);
                }
            }
        }
        System.out.println(makeAns());
    }

    private static int addJob(int nowTime, int t, char c, int workingTime) {
        if (nowTime >= t) {
            pq.offer(new Job(nowTime, c));
            return nowTime + workingTime;
        } else {
            pq.offer(new Job(t, c));
            return t + workingTime;
        }
    }

    private static String makeAns() {
        int idx = 1;
        while(!pq.isEmpty()) {
            Job job = pq.poll();
            if (job.color == 'B') {
                aAnsQ.offer(idx);
            } else {
                bAnsQ.offer(idx);
            }
            idx++;
        }
        sb.append(aAnsQ.size()).append("\n");
        while (!aAnsQ.isEmpty()) {
            sb.append(aAnsQ.poll()).append(" ");
        }
        sb.append("\n").append(bAnsQ.size()).append("\n");
        while (!bAnsQ.isEmpty()) {
            sb.append(bAnsQ.poll()).append(" ");
        }
        return sb.toString();
    }
}