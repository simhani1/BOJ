import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[][] arr;
    private static boolean[][] visited;
    private static int[] parent;
    private static PriorityQueue<Edge> pq = new PriorityQueue<Edge>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};

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

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        visited = new boolean[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        /* 섬 번호 붙이기 */
        int num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && arr[i][j] != 0) {
                    bfs(i, j, ++num);
                }
            }
        }
        /* 간선 정보 저장하기 */
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] != 0) {
                    for (int k = 0; k < 4; k++) {
                        searchingIsland(i, j, arr[i][j], k);
                    }
                }
            }
        }
        /* MST */
        parent = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            parent[i] = i;
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) != Find(to)) {
                Union(from, to);
                ans += cost;
            }
            if (isAllConnected(num)) {
                System.out.println(ans);
                System.exit(0);
            }
        }
        System.out.println(-1);
    }

    private static void searchingIsland(int x, int y, int num, int dir) {
        int len = 0;
        x += dx[dir];
        y += dy[dir];
        while (0 <= x && x < N && 0 <= y && y < M) {
            if (arr[x][y] == num) {
                return;
            } else if (arr[x][y] == 0) {
                len++;
            } else if (arr[x][y] != num) {
                if (len >= 2) {
                    /* 출발섬과 다르고 2 이상이면 */
                    pq.offer(new Edge(num, arr[x][y], len));

                }
                return;
            }
            x += dx[dir];
            y += dy[dir];
        }
    }

    private static boolean isAllConnected(int num) {
        int std = parent[1];
        for (int i = 2; i <= num; i++) {
            if (std != Find(i)) {
                return false;
            }
        }
        return true;
    }

    private static int Find(int a) {
        if (a == parent[a]) {
            return a;
        }
        return parent[a] = Find(parent[a]);
    }

    private static void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
        }
    }

    private static void bfs(int x, int y, int num) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(x, y));
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            arr[nowX][nowY] = num;
            visited[nowX][nowY] = true;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (isValid(nextX, nextY)) {
                    q.offer(new Node(nextX, nextY));
                }
            }
        }
    }

    private static boolean isValid(int nextX, int nextY) {
        return 0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY] && arr[nextX][nextY] == 1;
    }
}