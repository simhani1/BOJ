import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static final int INF = 123456789;
    private static int N, M;
    private static int sx, sy, gx, gy;
    private static char[][] arr;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};
    private static boolean[][][] visited;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N + 1][M + 1][65];
        arr = new char[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == '0') {
                    sx = i;
                    sy = j;
                }
            }
        }
        System.out.println(bfs());
    }

    static class Node {
        int x;
        int y;
        int cost;
        int keys;

        public Node(int x, int y, int cost, int keys) {
            this.x = x;
            this.y = y;
            this.cost = cost;
            this.keys = keys;
        }
    }

    private static int bfs() {
        int ans = -1;
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(sx, sy, 0, 0));
        visited[sx][sy][0] = true;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            int cost = node.cost;
            int keys = node.keys;
            if (arr[nowX][nowY] == '1') {
                ans = cost;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                    continue;
                }
                if (visited[nextX][nextY][keys] || arr[nextX][nextY] == '#') {
                    continue;
                }
                if (arr[nextX][nextY] == '.' || arr[nextX][nextY] == '0' || arr[nextX][nextY] == '1') {
                    visited[nextX][nextY][keys] = true;
                    q.offer(new Node(nextX, nextY, cost + 1, keys));
                } else if ('a' <= arr[nextX][nextY] && arr[nextX][nextY] <= 'f') {
                    int keyToNum = arr[nextX][nextY] - 'a';
                    visited[nextX][nextY][keys | (1 << keyToNum)] = true;
                    q.offer(new Node(nextX, nextY, cost + 1, keys | (1 << keyToNum)));
                } else if ('A' <= arr[nextX][nextY] && arr[nextX][nextY] <= 'F') {
                    int keyToNum = arr[nextX][nextY] - 'A';
                    if ((keys & (1 << keyToNum)) != 0) {
                        visited[nextX][nextY][keys] = true;
                        q.offer(new Node(nextX, nextY, cost + 1, keys));
                    }
                }
            }
        }
        return ans;
    }
}