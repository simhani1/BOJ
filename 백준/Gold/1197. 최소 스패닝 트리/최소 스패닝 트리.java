import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int V, E;
    private static int[] parent;
    private static PriorityQueue<Edge> pq = new PriorityQueue<Edge>((e1, e2) -> Integer.compare(e1.cost, e2.cost));

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        parent = new int[V + 1];
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            pq.add(new Edge(A, B, C));
            pq.add(new Edge(B, A, C));
        }
        int result = 0;
        int cnt = 0;
        while (!pq.isEmpty() || cnt != V - 1) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) != Find(to)) {
                Union(from, to);
                result += cost;
                cnt++;
            }
        }
        System.out.println(result);
    }

    private static void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
        }
    }

    private static int Find(int num) {
        if (parent[num] == num) {
            return num;
        }
        return parent[num] = Find(parent[num]);
    }

    static class Edge {
        int from;
        int to;
        int cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}