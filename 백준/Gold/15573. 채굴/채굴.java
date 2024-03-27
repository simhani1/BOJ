import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K;
    private static int[][] arr;
    private static int[] dx = {0, -1, 0, 1};
    private static int[] dy = {-1, 0, 1, 0};

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N + 2][M + 2];
        for (int i = N; i >= 1; i--) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int l = 1, r = 1000000, ans = Integer.MAX_VALUE;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(mid)) {
                r = mid - 1;
                ans = Math.min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        System.out.println(ans);
    }

    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static boolean isPossible(int target) {
        boolean[][] visited = new boolean[N + 1][M + 1];
        Queue<Node> q = new ArrayDeque<>();
        for (int j = 1; j <= M; j++) {
            if (arr[N][j] <= target) {
                q.offer(new Node(N, j));
                visited[N][j] = true;
            }
        }
        for (int i = 1; i < N; i++) {
            if (arr[i][1] <= target) {
                q.offer(new Node(i, 1));
                visited[i][1] = true;
            }
            if (arr[i][M] <= target) {
                q.offer(new Node(i, M));
                visited[i][M] = true;
            }
        }
        while (!q.isEmpty()) {
            Node node = q.poll();
            int nowX = node.x;
            int nowY = node.y;
            for (int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (1 <= nextX && nextX <= N && 1 <= nextY && nextY < M) {
                    if (!visited[nextX][nextY] && arr[nextX][nextY] <= target) {
                        q.offer(new Node(nextX, nextY));
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (visited[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt >= K;
    }
}