import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int R, C, T;
    private static int[][] arr = new int[51][51];
    private static int[][] purifier = new int[2][2];
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        boolean flag = false;
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == -1 && !flag) {
                    flag = true;
                    purifier[0] = new int[]{i, j};
                    purifier[1] = new int[]{i + 1, j};
                }
            }
        }
        while (T-- > 0) {
            /* 미세먼지 확산 */
            spread();
            /* 공기청정기 동작 */
            cleanTop();
            cleanBottom();
        }
        System.out.println(calc());
    }
    
    private static void spread() {
        Queue<Pos> q = new ArrayDeque<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                /* 미세먼지 */
                if (arr[i][j] > 0) {
                    q.offer(new Pos(i, j, arr[i][j]));
                }
            }
        }
        while (!q.isEmpty()) {
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            int originDust = pos.dust;
            int cnt = 0;
            int dust = (int) Math.floor(originDust / 5.0);
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (isValid(nextX, nextY)) {
                    arr[nextX][nextY] += dust;
                    cnt++;
                }
            }
            arr[nowX][nowY] -= (cnt * dust);
        }
    }

    private static boolean isValid(int nextX, int nextY) {
        return 0 <= nextX && nextX < R && 0 <= nextY && nextY < C && arr[nextX][nextY] != -1;
    }

    private static void cleanTop() {
        int x = purifier[0][0];
        int y = purifier[0][1];
        /* 좌 */
        for (int i = x - 1; i >= 1; i--) {
            arr[i][0] = arr[i - 1][0];
        }
        /* 상 */
        for (int j = 1; j < C; j++) {
            arr[0][j - 1] = arr[0][j];
        }
        /* 우 */
        for (int i = 1; i <= x; i++) {
            arr[i - 1][C - 1] = arr[i][C - 1];
        }
        /* 하 */
        for (int j = C - 1; j > 1; j--) {
            arr[x][j] = arr[x][j - 1];
        }
        arr[x][1] = 0;
    }

    private static void cleanBottom() {
        int x = purifier[1][0];
        int y = purifier[1][1];
        /* 좌 */
        for (int i = x + 1; i < R - 1; i++) {
            arr[i][0] = arr[i + 1][0];
        }
        /* 하 */
        for (int j = 0; j < C - 1; j++) {
            arr[R - 1][j] = arr[R - 1][j + 1];
        }
        /* 우 */
        for (int i = R - 1; i > x; i--) {
            arr[i][C - 1] = arr[i - 1][C - 1];
        }
        /* 상 */
        for (int j = C - 1; j > 1; j--) {
            arr[x][j] = arr[x][j - 1];
        }
        arr[x][1] = 0;
    }

    private static int calc() {
        int sum = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] > 0) {
                    sum += arr[i][j];
                }
            }
        }
        return sum;
    }

    static class Pos {

        int x;
        int y;
        int dust;

        public Pos(int x, int y, int dust) {
            this.x = x;
            this.y = y;
            this.dust = dust;
        }
    }
}