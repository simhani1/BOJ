import java.awt.print.PrinterJob;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int R, C, sx, sy;
    private static final int INF = Integer.MAX_VALUE;
    private static int[][] water;
    private static int[][] hatchhog;
    private static char[][] arr;
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        arr = new char[R + 1][C + 1];
        water = new int[R + 1][C + 1];
        hatchhog = new int[R + 1][C + 1];
        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                water[i][j] = INF;
                hatchhog[i][j] = INF;
            }
        }
        flood();
        moving();
    }

    private static void moving() {
        boolean[][] visited = new boolean[R + 1][C + 1];
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(sx, sy, 0));
        visited[sx][sy] = true;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            int time = node.time;
            hatchhog[nowX][nowY] = time;
            if (arr[nowX][nowY] == 'D') {
                System.out.println(time);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                int nextTime = time + 1;
                if (isValid(nextX, nextY) && arr[nextX][nextY] != 'X' && arr[nextX][nextY] != '*' && !visited[nextX][nextY]) {
                    if (water[nextX][nextY] > nextTime) {
                        q.offer(new Node(nextX, nextY, nextTime));
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        System.out.println("KAKTUS");
    }

    static class Node {
        int x;
        int y;
        int time;

        public Node(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }

    private static void flood() {
        boolean[][] visited = new boolean[R + 1][C + 1];
        Queue<Node> q = new ArrayDeque<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] == '*') {
                    q.offer(new Node(i, j, 0));
                    water[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            int time = node.time;
            water[nowX][nowY] = time;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                int nextTime = time + 1;
                if (isValid(nextX, nextY) && arr[nextX][nextY] == '.' && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    q.offer(new Node(nextX, nextY, nextTime));
                }
            }
        }
    }

    private static boolean isValid(int x, int y) {
        return 0 <= x && x < R && 0 <= y && y < C;
    }
}