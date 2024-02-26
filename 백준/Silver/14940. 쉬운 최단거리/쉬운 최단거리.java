import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    private static final int[] dx = {1, -1, 0, 0};
    private static final int[] dy= {0, 0, 1, -1};
    private static int n, m;
    private static boolean[][] isVisited;
    private static int[][] board;
    private static class Point {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static boolean isRightWay(int nx, int ny) {
        return (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != 0 && !isVisited[nx][ny]);
    }
    
    private static void BFS(int sx, int sy) {
        board[sx][sy] = 0;
        isVisited = new boolean[n][m];
        isVisited[sx][sy] = true;
        Deque<Point> queue = new ArrayDeque<>();
        queue.add(new Point(sx, sy));
        while (!queue.isEmpty()) {
            Point p = queue.poll();
            for (int d = 0; d < 4; ++d) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];
                if (isRightWay(nx, ny)) {
                    board[nx][ny] = board[p.x][p.y] + 1;
                    isVisited[nx][ny] = true;
                    queue.add(new Point(nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        board = new int[n][m];
        int sx = 0, sy = 0;
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 2) {
                    sx = i;
                    sy = j;
                } else if (board[i][j] == 1) board[i][j] = -1;
            }
        }
        BFS(sx, sy);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                sb.append(board[i][j]).append(' ');
            sb.append('\n');
        }
        System.out.print(sb.toString());
    }
}