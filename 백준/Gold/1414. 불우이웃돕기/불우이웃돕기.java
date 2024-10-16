import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static int[][] arr;
    private static int[] parent;
    private static PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));

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

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][N + 1];
        parent = new int[N + 1];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            int cost = 0;
            for (int j = 0; j < N; j++) {
                char c = line.charAt(j);
                if (c == '0') {
                    cost = 0;
                } else if ('a' <= c && c <= 'z') {
                    cost = c - 'a' + 1;
                } else if ('A' <= c && c <= 'Z') {
                    cost = c - 'A' + 27;
                }
                if (i != j && cost != 0) {
                    pq.offer(new Edge(i, j, cost));
                }
                sum += cost;
            }
        }
        int cnt = 0;
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) != Find(to)) {
                Union(from, to);
                sum -= cost;
                cnt++;
            }
        }
        System.out.println(cnt == N - 1 ? sum : -1);
    }

    private static void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
        }
    }

    private static int Find(int a) {
        if (a == parent[a]) {
            return a;
        }
        return parent[a] = Find(parent[a]);
    }
}