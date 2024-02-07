import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T, N;
    private static final int PAPER_SIZE = 10;
    private static final int MAX_SIZE = 100;
    private static int[][] arr = new int[110][110];
    private static boolean[][] visited = new boolean[110][110];
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            arr[x][y]++;
            arr[x + PAPER_SIZE][y]--;
            arr[x][y + PAPER_SIZE]--;
            arr[x + PAPER_SIZE][y + PAPER_SIZE]++;
        }
        for (int i = 0; i <= MAX_SIZE; i++) {
            for (int j = 1; j <= MAX_SIZE; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }
        for (int j = 0; j <= MAX_SIZE; j++) {
            for (int i = 1; i <= MAX_SIZE; i++) {
                arr[i][j] += arr[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= MAX_SIZE; i++) {
            for (int j = 0; j <= MAX_SIZE; j++) {
                if (arr[i][j] != 0) {
                    ans += bfs(i, j);
                }
            }
        }
        System.out.println(ans);
    }

    private static int bfs(int x, int y) {
        int cnt = 0;
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(x, y));
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            if (visited[nowX][nowY]) {
                continue;
            }
            visited[nowX][nowY] = true;
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 0 || nextX > MAX_SIZE || nextY < 0 || nextY > MAX_SIZE) {
                    continue;
                }
                if (arr[nextX][nextY] > 0) {
                    q.offer(new Node(nextX, nextY));
                }
            }
        }
        return cnt;
    }
}

class Node {
    int x;
    int y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}