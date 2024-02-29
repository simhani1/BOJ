import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, ans = 0;
    private static int[][] arr;
    private static boolean[][] wall;
    private static boolean[][] visited;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        wall = new boolean[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        makeWall(0);
        System.out.println(ans);
    }

    private static void makeWall(int cnt) {
        /* 벽을 모두 세운 경우 */
        if (cnt == 3) {
            int[][] tmp = new int[N + 1][];
            for (int i = 0; i < N; i++) {
                tmp[i] = Arrays.copyOf(arr[i], arr[i].length);
            }
            /* bfs */
            bfs(tmp);
            int safeCnt = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (tmp[i][j] == 0) {
                        safeCnt++;
                    }
                }
            }
            ans = Math.max(ans, safeCnt);
            return;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0 && !wall[i][j]) {
                    wall[i][j] = true;
                    arr[i][j] = 1;
                    makeWall(cnt + 1);
                    wall[i][j] = false;
                    arr[i][j] = 0;
                }
            }
        }
    }

    private static void bfs(int[][] tmp) {
        Queue<Node> q = new ArrayDeque<>();
        visited = new boolean[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tmp[i][j] == 2) {
                    q.offer(new Node(i, j));
                }
            }
        }
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            visited[nowX][nowY] = true;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (isValid(nextX, nextY) && tmp[nextX][nextY] == 0) {
                    tmp[nextX][nextY] = 2;
                    q.offer(new Node(nextX, nextY));
                }
            }
        }
    }

    private static boolean isValid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < M && !visited[x][y];
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