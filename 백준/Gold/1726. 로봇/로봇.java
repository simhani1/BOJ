import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int sx, sy, sDir, gx, gy, gDir;
    private static int[][] arr;
    private static boolean[][][] visited;
    private static int[] dx = {0, 0, 1, -1};
    private static int[] dy = {1, -1, 0, 0};

    static class Pos {
        int x;
        int y;
        int dir;
        int cnt;

        public Pos(int x, int y, int dir, int cnt) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.cnt = cnt;
        }

        @Override
        public String toString() {
            return "Pos{" +
                "x=" + x +
                ", y=" + y +
                ", dir=" + dir +
                ", cnt=" + cnt +
                '}';
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        visited = new boolean[N][M][4];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        sx = Integer.parseInt(st.nextToken()) - 1;
        sy = Integer.parseInt(st.nextToken()) - 1;
        sDir = Integer.parseInt(st.nextToken()) - 1;
        st = new StringTokenizer(br.readLine());
        gx = Integer.parseInt(st.nextToken()) - 1;
        gy = Integer.parseInt(st.nextToken()) - 1;
        gDir = Integer.parseInt(st.nextToken()) - 1;
        System.out.println(bfs());
    }

    private static int bfs() {
        Queue<Pos> q = new ArrayDeque<>();
        q.offer(new Pos(sx, sy, sDir, 0));
        visited[sx][sy][sDir] = true;
        while (!q.isEmpty()) {
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            int nowDir = pos.dir;
            int nowCnt = pos.cnt;
            if (nowX == gx && nowY == gy && nowDir == gDir) {
                return nowCnt;
            }
            for (int i = 1; i <= 3; i++) {
                int nextX = nowX + i * dx[nowDir];
                int nextY = nowY + i * dy[nowDir];
                if (canMove(nowX, nowY, nowDir, i)) {
                    visited[nextX][nextY][nowDir] = true;
                    q.offer(new Pos(nextX, nextY, nowDir, nowCnt + 1));
                }
            }
            int nextDir = changeDir(nowDir, false);
            if (!visited[nowX][nowY][nextDir]) {
                visited[nowX][nowY][nextDir] = true;
                q.offer(new Pos(nowX, nowY, nextDir, nowCnt + 1));
            }
            nextDir = changeDir(nowDir, true);
            if (!visited[nowX][nowY][nextDir]) {
                visited[nowX][nowY][nextDir] = true;
                q.offer(new Pos(nowX, nowY, nextDir, nowCnt + 1));
            }
        }
        return 0;
    }

    private static boolean canMove(int nowX, int nowY, int dir, int turn) {
        int nextX = 0;
        int nextY = 0;
        for (int i = 1; i <= turn; i++) {
            nextX = nowX + i * dx[dir];
            nextY = nowY + i * dy[dir];
            if (!isValid(nextX, nextY)) {
                return false;
            }
            if (arr[nextX][nextY] == 1) {
                return false;
            }
        }
        return !visited[nextX][nextY][dir];
    }

    private static boolean isValid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < M;
    }

    private static int changeDir(int dir, boolean left) {
        if (left) {
            if (dir == 0) {
                return 3;
            } else if (dir == 1) {
                return 2;
            } else if (dir == 2) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (dir == 0) {
                return 2;
            } else if (dir == 1) {
                return 3;
            } else if (dir == 2) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}