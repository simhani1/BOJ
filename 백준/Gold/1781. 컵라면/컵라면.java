import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static List<Problem> problems = new ArrayList<>();
    private static PriorityQueue<Integer> pq = new PriorityQueue<>();

    static class Problem {
        int deadline;
        int reward;

        public Problem(int deadline, int reward) {
            this.deadline = deadline;
            this.reward = reward;
        }
    }

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            problems.add(new Problem(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        problems.sort((o1, o2) -> {
            if (o1.deadline == o2.deadline) {
                return Integer.compare(o1.reward, o2.reward) * -1;
            }
            return Integer.compare(o1.deadline, o2.deadline);
        });
        System.out.println(solve());
    }

    private static long solve() {
        long ans = 0;
        int now = 1;
        for (Problem problem : problems) {
            int deadline = problem.deadline;
            int reward = problem.reward;
            if (deadline >= now) {
                pq.offer(reward);
                now++;
            } else {
                if (reward > pq.peek()) {
                    pq.poll();
                    pq.offer(reward);
                }
            }
        }
        while (!pq.isEmpty()) {
            ans += pq.poll();
        }
        return ans;
    }

}