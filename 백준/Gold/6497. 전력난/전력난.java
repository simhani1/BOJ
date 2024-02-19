import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static boolean[] visited;
    private static List<Edge>[] arr;
    private static PriorityQueue<Edge> pq;

    public static void main(String[] args) throws Exception {
        while (true) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            if (M == 0 && N == 0) {
                break;
            }
            /* init */
            visited = new boolean[M + 1];
            pq = new PriorityQueue<>((e1, e2) -> Integer.compare(e1.cost, e2.cost));
            arr = new ArrayList[M + 1];
            for (int i = 0; i <= M; i++) {
                arr[i] = new ArrayList<>();
            }
            int sum = 0;
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int A = Integer.parseInt(st.nextToken());
                int B = Integer.parseInt(st.nextToken());
                int C = Integer.parseInt(st.nextToken());
                arr[A].add(new Edge(B, C));
                arr[B].add(new Edge(A, C));
                sum += C;
            }
            /* 0번째 집에서부터 시작 */
            sb.append(solve(sum))
                    .append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int solve(int sum) {
        visited[0] = true;
        for (int i = 0; i < arr[0].size(); i++) {
            pq.add(arr[0].get(i));
        }
        /* 최소 간선 확장 */
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int now = edge.to;
            int cost = edge.cost;
            if (visited[now]) {
                continue;
            }
            visited[now] = true;
            sum -= cost;
            for (int i = 0; i < arr[now].size(); i++) {
                pq.add(arr[now].get(i));
            }
        }
        return sum;
    }

    static class Edge {
        int to;
        int cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
}