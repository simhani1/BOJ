import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;

    static class Customer {
        int id;
        int reservedAt;
        int arrivedAt;

        public Customer(int id, int reservedAt, int arrivedAt) {
            this.id = id;
            this.reservedAt = reservedAt;
            this.arrivedAt = arrivedAt;
        }
    }
    static List<Customer> customers = new ArrayList<>();
    static int[] reservation = new int[300_005];
    static int[] arrivedTimeTable;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arrivedTimeTable = new int[N + 1];
        visited = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int t1 = Integer.parseInt(st.nextToken());
            int t2 = Integer.parseInt(st.nextToken());
            customers.add(new Customer(i, t1, t2));
            reservation[t1] = i;
            arrivedTimeTable[i] = t2;
        }
        customers.sort((o1, o2) -> {
            if (o1.arrivedAt == o2.arrivedAt) {
                return Integer.compare(o1.reservedAt, o2.reservedAt);
            }
            return Integer.compare(o1.arrivedAt, o2.arrivedAt);
        });
        /*
         * 현재 시간에 예약한 사람이 이미 기다리고 있으면
         *   새치기
         * 없고 대기자들이 있다면
         *   제일 먼저 온 사람 입장
         * */
        int ans = 0;
        int idx = 0;
        Queue<Customer> q = new ArrayDeque<>();  // 입장한 사람들 저장
        Set<Integer> waitingSet = new HashSet<>();
        for (int t = 1; t <= 300_000; t++) {
            // 현재 시간까지 도착한 사람들 큐에 저장
            while (idx < N && customers.get(idx).arrivedAt <= t) {
                q.offer(customers.get(idx));
                waitingSet.add(customers.get(idx).id);
                idx++;
            }
            // 현재 시간에 예약한 사람
            int id = reservation[t];
            // 예약자가 이미 와서 기다리고 있으면 먼저 입장
            if (waitingSet.contains(id)) {
                waitingSet.remove(id);
                ans = Math.max(ans, t - arrivedTimeTable[id]);
                visited[id] = true;
            } else if (!q.isEmpty()) {
                // 예약자가 아직 안왔으니까 대기 줄의 첫 손님 입장
                Customer customer = q.poll();
                ans = Math.max(ans, t - customer.arrivedAt);
                waitingSet.remove(customer.id);
                visited[customer.id] = true;
            }
            // waitingSet에서는 제거된 고객이 큐에 남아있어서 제거해야 함
            while (!q.isEmpty() && visited[q.peek().id]) {
                q.poll();
            }
        }
        System.out.println(ans);
    }
}