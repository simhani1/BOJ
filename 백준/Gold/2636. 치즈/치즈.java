import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, ans, T = 0;
    private static int[][] arr;
    private static boolean[][] visited;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};
    private static Queue<Node> q = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        while (true) {
            T++;
            visited = new boolean[N + 1][M + 1];
            if (bfs()) {
                break;
            }
        }
        sb.append(T - 1).append("\n").append(ans);
        System.out.println(sb.toString());
    }

    private static boolean bfs() {
        int cnt = 0;
        q.offer(new Node(0, 0));
        visited[0][0] = true;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                    continue;
                }
                if (visited[nextX][nextY]) {
                    continue;
                }
                visited[nextX][nextY] = true;
                if (arr[nextX][nextY] == 0) {
                    q.offer(new Node(nextX, nextY));
                } else {
                    arr[nextX][nextY] = 0;
                    cnt++;
                }
            }
        }
        if (cnt > 0) {
            ans = cnt;
            return false;
        }else {
            return true;
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
}