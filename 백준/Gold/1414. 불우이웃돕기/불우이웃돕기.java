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
    private static int N;
    private static int[] parent;
    private static PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> Integer.compare(e1.cost, e2.cost));

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        parent = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            char[] arr = br.readLine().toCharArray();
            for (int j = 0; j < N; j++) {
                if (arr[j] == '0') {
                    continue;
                }
                int cost = 0;
                if (arr[j] >= 'a') {
                    cost = arr[j] - 'a' + 1;
                } else if(arr[j] >= 'A') {
                    cost = arr[j] - 'A' + 27;
                }
                pq.add(new Edge(i, j, cost));
                sum += cost;
            }
        }
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) != Find(to)) {
                Union(from, to);
                sum -= cost;
            }
        }
        for (int i = 0; i < N; i++) {
            if (Find(i) != 0) {
                sum = -1;
            }
        }
        System.out.println(sum);
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