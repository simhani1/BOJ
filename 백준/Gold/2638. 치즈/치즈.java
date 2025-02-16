import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[][] arr;
    private static int[] dx = {0, 0, 1, -1};
    private static int[] dy = {1, -1, 0, 0};
    private static List<Pos> list = new ArrayList<>();

    static class Pos {
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        /* input */
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    list.add(new Pos(i, j));
                }
            }
        }
        /* solve */
        int cnt = 0;
        while (!list.isEmpty()) {
            setAir();
            melting();
            cnt++;
        }
        System.out.println(cnt);
    }

    private static void melting() {
        for (int i = 0; i < list.size(); i++) {
            Pos pos = list.get(i);
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                if (arr[pos.x + dx[j]][pos.y + dy[j]] == -1) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                arr[pos.x][pos.y] = 0;
                list.remove(i);
                i--;
            }
        }
    }

    private static void setAir() {
        Queue<Pos> q = new ArrayDeque<>();
        q.offer(new Pos(0, 0));
        boolean[][] visited = new boolean[N][M];
        visited[0][0] = true;
        arr[0][0] = -1;
        while (!q.isEmpty()) {
            Pos pos = q.poll();
            int nowX = pos.x;
            int nowY = pos.y;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (!(0 <= nextX && nextX < N & 0 <= nextY && nextY < M)) {
                    continue;
                }
                if (visited[nextX][nextY]) {
                    continue;
                }
                if (arr[nextX][nextY] == 1) {
                    continue;
                }
                visited[nextX][nextY] = true;
                arr[nextX][nextY] = -1;
                q.offer(new Pos(nextX, nextY));
            }
        }
    }

}