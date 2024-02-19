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
    private static PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Integer.compare(e1.cost, e2.cost));

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N + 1];
        arr = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            arr[A].add(new Edge(B, C));
            arr[B].add(new Edge(A, C));
        }
        System.out.println(solve());
    }

    private static int solve() {
        int result = 0;
        int maxCost = 0;
        visited[1] = true;
        for (Edge edge : arr[1]) {
            pq.add(edge);
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
            result += cost;
            maxCost = Math.max(maxCost, cost);
            for (Edge nextEdge : arr[now]) {
                pq.add(nextEdge);
            }
        }
        return result - maxCost;
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