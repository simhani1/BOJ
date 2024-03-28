import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N;
    private static int sx, sy, gx, gy;
    private static List<Node> stores = new ArrayList<>();

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            stores = new ArrayList<>();
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            sx = Integer.parseInt(st.nextToken());
            sy = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                stores.add(new Node(x, y));
            }
            st = new StringTokenizer(br.readLine());
            gx = Integer.parseInt(st.nextToken());
            gy = Integer.parseInt(st.nextToken());
            bfs();
        }
        System.out.println(sb.toString());
    }

    private static void bfs() {
        if (calcDist(sx, sy, gx, gy) <= 1000) {
            sb.append("happy\n");
            return;
        }
        Queue<Node> q = new ArrayDeque<>();
        boolean[] visited = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            Node node = stores.get(i);
            if (calcDist(sx, sy, node.x, node.y) <= 1000) {
                q.offer(node);
                visited[i] = true;
            }
        }
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            if (calcDist(nowX, nowY, gx, gy) <= 1000) {
                sb.append("happy\n");
                return;
            }
            for (int i = 0; i < N; i++) {
                Node store = stores.get(i);
                if (!visited[i] && calcDist(nowX, nowY, store.x, store.y) <= 1000) {
                    visited[i] = true;
                    q.offer(new Node(store.x, store.y));
                }
            }
        }
        sb.append("sad\n");
    }

    private static int calcDist(int fromX, int fromY, int toX, int toY) {
        return Math.abs(fromX - toX) + Math.abs(fromY - toY);
    }
}