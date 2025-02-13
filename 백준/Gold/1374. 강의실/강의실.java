import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static PriorityQueue<Lecture> room = new PriorityQueue<>(
        (o1, o2) -> Integer.compare(o1.finishedAt, o2.finishedAt));
    private static PriorityQueue<Lecture> pq = new PriorityQueue<>((o1, o2) -> {
        if (o1.startedAt == o2.startedAt) {
            return Integer.compare(o1.finishedAt, o2.finishedAt);
        }
        return Integer.compare(o1.startedAt, o2.startedAt);
    });

    static class Lecture {
        int num;
        int startedAt;
        int finishedAt;

        public Lecture(int num, int startedAt, int finishedAt) {
            this.num = num;
            this.startedAt = startedAt;
            this.finishedAt = finishedAt;
        }
    }

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int startedAt = Integer.parseInt(st.nextToken());
            int finishedAt = Integer.parseInt(st.nextToken());
            pq.offer(new Lecture(num, startedAt, finishedAt));
        }
        int ans = 1;
        room.offer(pq.poll());
        while (!pq.isEmpty()) {
            Lecture lecture = pq.poll();
            Lecture targetLecture = room.peek();
            // 교체 가능한 경우
            if (lecture.startedAt >= targetLecture.finishedAt) {
                room.poll();
            }
            room.offer(lecture);
            ans = Math.max(ans, room.size());
        }
        System.out.println(ans);
    }
}