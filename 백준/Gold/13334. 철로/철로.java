import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, D;
    private static List<Pos> list = new ArrayList<>();

    static class Pos {
        int home;
        int office;

        public Pos(int home, int office) {
            this.home = home;
            this.office = office;
        }

        @Override
        public String toString() {
            return "Pos{" +
                    "home=" + home +
                    ", office=" + office +
                    '}';
        }
    }

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int home = Integer.parseInt(st.nextToken());
            int office = Integer.parseInt(st.nextToken());
            list.add(new Pos(Math.min(home, office), Math.max(home, office)));
        }
        D = Integer.parseInt(br.readLine());
        Collections.sort(list, (o1, o2) -> Integer.compare(o1.office, o2.office));
        System.out.println(solve());
    }

    /*
    * 사무실부터 D만큼 철로를 건설
    * 이전까지 포함됐던 집의 좌표들 중 현재 철로의 시작점보다 작은 것들은 제거
    * 현재 집의 위치가 철로의 시작점보다 크면 저장
    * */
    private static int solve() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        for (Pos p : list) {
            int start = p.office - D;
            while (!pq.isEmpty() && pq.peek() < start) {
                pq.poll();
            }
            if (start <= p.home) {
                pq.offer(p.home);
            }
            ans = Math.max(ans, pq.size());
        }
        return ans;
    }
}