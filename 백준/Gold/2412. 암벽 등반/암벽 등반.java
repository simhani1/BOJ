import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, T;
    private static List<Node> list = new ArrayList<>();
    private static int[] dist;
    private static final int INF = 123456789;

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        dist = new int[N + 1];
        Arrays.fill(dist, INF);
        list.add(new Node(0, 0));
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list.add(new Node(x, y));
        }
        Collections.sort(list, (o1, o2) -> {
            if (o1.x == o2.x) {
                return Integer.compare(o1.y, o2.y);
            }
            return Integer.compare(o1.x, o2.x);
        });
        System.out.println(bfs());
    }

    private static int bfs() {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(0);
        dist[0] = 0;
        while (!q.isEmpty()) {
            int idx = q.poll();
            Node now = list.get(idx);
            if (now.y == T) {
                return dist[idx];
            }
            /* 왼쪽 */
            for (int i = idx - 1; i >= 1; i--) {
                Node next = list.get(i);
                if (calcDist(now.x, next.x) > 2) {
                    break;
                }
                if (calcDist(now.y, next.y) > 2) {
                    continue;
                }
                if (dist[i] == INF) {
                    dist[i] = dist[idx] + 1;
                    q.offer(i);
                }
            }
            /* 오른쪽 */
            for (int i = idx + 1; i <= N; i++) {
                Node next = list.get(i);
                if (calcDist(now.x, next.x) > 2) {
                    break;
                }
                if (calcDist(now.y, next.y) > 2) {
                    continue;
                }
                if (dist[i] == INF) {
                    dist[i] = dist[idx] + 1;
                    q.offer(i);
                }
            }
        }
        return -1;
    }

    private static int calcDist(int num1, int num2) {
        return Math.abs(num1 - num2);
    }
}