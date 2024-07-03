import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K;
    private static int[][] arr;
    private static int[][][] dist;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};
    private static final int INF = Integer.MAX_VALUE;

    static class Pos {
        int x;
        int y;
        int cnt;

        public Pos(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        dist = new int[N + 1][M + 1][K + 1];
        for (int i = 0; i < N; i++) {
            char[] charArray = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                arr[i][j] = charArray[j] - '0';
                for (int k = 0; k <= K; k++) {
                    dist[i][j][k] = INF;
                }
            }
        }
        int ans = bfs(0, 0);
        System.out.println(ans == INF ? -1 : ans);
    }

    private static int bfs(int x, int y) {
        Queue<Pos> q = new ArrayDeque<>();
        q.add(new Pos(x, y, 0));
        dist[x][y][0] = 1;
        while (!q.isEmpty()) {
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            int nowCnt = pos.cnt;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
                    /* 벽 부수고 이동하기 */
                    if (nowCnt + 1 <= K && arr[nextX][nextY] == 1
                        && dist[nextX][nextY][nowCnt + 1] > dist[nowX][nowY][nowCnt] + 1) {
                        dist[nextX][nextY][nowCnt + 1] = dist[nowX][nowY][nowCnt] + 1;
                        q.offer(new Pos(nextX, nextY, nowCnt + 1));
                    }
                    /* 벽 부수지 않고 이동하기 */
                    if (arr[nextX][nextY] == 0
                        && dist[nextX][nextY][nowCnt] > dist[nowX][nowY][nowCnt] + 1) {
                        dist[nextX][nextY][nowCnt] = dist[nowX][nowY][nowCnt] + 1;
                        q.offer(new Pos(nextX, nextY, nowCnt));
                    }
                }
            }
        }
        int tmp = INF;
        for (int i = 0; i <= K; i++) {
            tmp = Math.min(tmp, dist[N - 1][M - 1][i]);
        }
        return tmp;
    }

}