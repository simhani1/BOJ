import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, K;
    private static int[][] arr;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};
    private static Queue<Pos> q = new ArrayDeque<>();
    private static final int SPACE = 1500;
    private static final int MAX_SIZE = 3050;

    static class Pos {
        int x;
        int y;
        int time;

        public Pos(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                if (str.charAt(j) == 'o') {
                    arr[i + SPACE][j + SPACE] = 1;
                    q.offer(new Pos(i + SPACE, j + SPACE, 0));
                }
            }
        }
        K = Integer.parseInt(br.readLine());
        System.out.println(bfs());
    }

    private static int bfs() {
        int cnt = 0;
        while (!q.isEmpty()) {
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            int nowTime = pos.time;
            cnt++;
            if (nowTime == K) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (!(0 <= nextX && nextX < MAX_SIZE && 0 <= nextY && nextY < MAX_SIZE)) {
                    continue;
                }
                if (arr[nextX][nextY] == 0) {
                    q.offer(new Pos(nextX, nextY, nowTime + 1));
                    arr[nextX][nextY] = 1;
                }
            }
        }
        return cnt;
    }
}