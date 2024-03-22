import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N;
    private static int[][] arr;
    private static int[][] dist;
    private static int[] dx = {0, 0, 1, -1};
    private static int[] dy = {1, -1, 0, 0};

    static class Node {
        int x;
        int y;
        int cost;

        public Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        int t = 1;
        while (true) {
            N = Integer.parseInt(br.readLine());
            if (N == 0) {
                break;
            }
            init();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            dijkstra();
            sb.append("Problem ").append(t++).append(": ").append(dist[N - 1][N - 1]).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dijkstra() {
        dist[0][0] = arr[0][0];
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        pq.offer(new Node(0, 0, dist[0][0]));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int nowX = node.x;
            int nowY = node.y;
            int cost = node.cost;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
                    if (cost + arr[nextX][nextY] < dist[nextX][nextY]) {
                        dist[nextX][nextY] = cost + arr[nextX][nextY];
                        pq.offer(new Node(nextX, nextY, dist[nextX][nextY]));
                    }
                }
            }
        }
    }

    private static void init() {
        arr = new int[N][N];
        dist = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
    }
}